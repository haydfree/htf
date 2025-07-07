#include <htf_test.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Global test state
static htf_test_suite_t* g_test_suites = NULL;
static htf_test_config_t g_config = {
    .verbose = false,
    .stop_on_failure = false,
    .filter_pattern = NULL,
    .benchmark_mode = false,
    .benchmark_iterations = 1000,
    .output_stream = stdout
};

// Memory tracking (optional)
static size_t g_alloc_count = 0;
static size_t g_free_count = 0;

void htf_test_init(htf_test_config_t* config) {
    if (config) {
        g_config = *config;
    }
}

static void htf_test_register_suite(htf_test_suite_t* suite) {
    suite->next = g_test_suites;
    g_test_suites = suite;
}

static bool htf_test_matches_filter(const char* name) {
    if (!g_config.filter_pattern) return true;
    // Simple substring matching for now
    return strstr(name, g_config.filter_pattern) != NULL;
}

static void htf_test_run_case_internal(htf_test_case_t* test_case, htf_test_suite_t* suite) {
    if (!htf_test_matches_filter(test_case->name)) {
        return;
    }

    if (test_case->skip) {
        fprintf(g_config.output_stream, "SKIP %s.%s: %s\n",
                suite->name, test_case->name, test_case->skip_reason);
        return;
    }

    if (g_config.verbose) {
        fprintf(g_config.output_stream, "RUN  %s.%s\n", suite->name, test_case->name);
    }

    clock_t start = clock();
    
    if (suite->setup) {
        suite->setup();
    }

    test_case->test_fn();

    if (suite->teardown) {
        suite->teardown();
    }

    clock_t end = clock();
    double duration_ms = ((double)(end - start) * 1000.0) / CLOCKS_PER_SEC;

    fprintf(g_config.output_stream, "PASS %s.%s (%.2f ms)\n",
            suite->name, test_case->name, duration_ms);
}

void htf_test_run_case(const char* suite_name, const char* case_name) {
    htf_test_suite_t* suite = g_test_suites;
    while (suite) {
        if (strcmp(suite->name, suite_name) == 0) {
            htf_test_case_t* test_case = suite->cases;
            while (test_case) {
                if (strcmp(test_case->name, case_name) == 0) {
                    htf_test_run_case_internal(test_case, suite);
                    return;
                }
                test_case = test_case->next;
            }
            fprintf(stderr, "Error: Test case '%s' not found in suite '%s'\n",
                    case_name, suite_name);
            return;
        }
        suite = suite->next;
    }
    fprintf(stderr, "Error: Test suite '%s' not found\n", suite_name);
}

void htf_test_run_suite(const char* suite_name) {
    htf_test_suite_t* suite = g_test_suites;
    while (suite) {
        if (strcmp(suite->name, suite_name) == 0) {
            htf_test_case_t* test_case = suite->cases;
            while (test_case) {
                htf_test_run_case_internal(test_case, suite);
                test_case = test_case->next;
            }
            return;
        }
        suite = suite->next;
    }
    fprintf(stderr, "Error: Test suite '%s' not found\n", suite_name);
}

void htf_test_run_all(void) {
    htf_test_suite_t* suite = g_test_suites;
    while (suite) {
        if (htf_test_matches_filter(suite->name)) {
            htf_test_case_t* test_case = suite->cases;
            while (test_case) {
                htf_test_run_case_internal(test_case, suite);
                test_case = test_case->next;
            }
        }
        suite = suite->next;
    }
}

void htf_test_fail(const char* file, int line, const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    
    fprintf(g_config.output_stream, "FAIL %s:%d: ", file, line);
    vfprintf(g_config.output_stream, fmt, args);
    fprintf(g_config.output_stream, "\n");
    
    va_end(args);
    
    if (g_config.stop_on_failure) {
        exit(1);
    }
}

void htf_test_skip(const char* reason) {
    // This is called from within a test case
    htf_test_case_t* current_case = NULL;
    htf_test_suite_t* current_suite = g_test_suites;
    
    // Find the current test case (this is a bit hacky)
    while (current_suite) {
        htf_test_case_t* test_case = current_suite->cases;
        while (test_case) {
            if (test_case->test_fn == __builtin_return_address(0)) {
                current_case = test_case;
                break;
            }
            test_case = test_case->next;
        }
        if (current_case) break;
        current_suite = current_suite->next;
    }
    
    if (current_case) {
        current_case->skip = true;
        current_case->skip_reason = reason;
    }
}

void htf_test_cleanup(void) {
    // Clean up test suites
    htf_test_suite_t* suite = g_test_suites;
    while (suite) {
        htf_test_suite_t* next = suite->next;
        free(suite);
        suite = next;
    }
    g_test_suites = NULL;
}

// Memory tracking functions
void htf_test_track_memory(void) {
    g_alloc_count = 0;
    g_free_count = 0;
}

void htf_test_check_leaks(void) {
    if (g_alloc_count != g_free_count) {
        fprintf(g_config.output_stream, 
                "WARNING: Possible memory leak detected! "
                "Allocations: %zu, Frees: %zu\n",
                g_alloc_count, g_free_count);
    }
}

// Constructor to register test suites
static void __attribute__((constructor)) htf_register_suites(void) {
    // This will be called for each test suite defined with HTF_TEST_SUITE
    extern htf_test_suite_t* _htf_current_suite;
    if (_htf_current_suite) {
        htf_test_register_suite(_htf_current_suite);
    }
} 
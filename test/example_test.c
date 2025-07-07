#include <htf_test.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Example test suite for string operations
HTF_TEST_SUITE(string_suite) {
    // Setup runs before each test case
    printf("Setting up string test suite...\n");
}

// Example test case
HTF_TEST_CASE(test_string_length) {
    const char* str = "Hello, World!";
    HTF_ASSERT_EQ(strlen(str), 13);
}

// Example test case with multiple assertions
HTF_TEST_CASE(test_string_compare) {
    const char* str1 = "Hello";
    const char* str2 = "Hello";
    const char* str3 = "World";
    
    HTF_ASSERT_STR_EQ(str1, str2);
    HTF_ASSERT(strcmp(str1, str3) != 0);
}

// Example test case that would be skipped
HTF_TEST_CASE(test_string_skip) {
    htf_test_skip("This test is not implemented yet");
    HTF_ASSERT(0); // This won't run
}

// Example test suite for memory operations
HTF_TEST_SUITE(memory_suite) {
    // Setup for memory tests
    htf_test_track_memory();
}

// Example test case with memory operations
HTF_TEST_CASE(test_memory_allocation) {
    char* str = malloc(10);
    HTF_ASSERT_NOT_NULL(str);
    strcpy(str, "test");
    HTF_ASSERT_STR_EQ(str, "test");
    free(str);
}

// Example benchmark test
HTF_TEST_CASE(benchmark_string_copy) {
    const char* src = "Hello, World!";
    char* dest = malloc(strlen(src) + 1);
    
    HTF_BENCHMARK({
        strcpy(dest, src);
    }, 1000);
    
    free(dest);
}

// Main test runner
int main(void) {
    // Configure the test runner
    htf_test_config_t config = {
        .verbose = true,
        .stop_on_failure = true,
        .filter_pattern = NULL,
        .benchmark_mode = false,
        .benchmark_iterations = 1000,
        .output_stream = stdout
    };
    
    htf_test_init(&config);
    
    // Run all tests
    htf_test_run_all();
    
    // Check for memory leaks
    htf_test_check_leaks();
    
    // Cleanup
    htf_test_cleanup();
    
    return 0;
} 
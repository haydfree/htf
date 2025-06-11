#ifndef HTF_LOG_H
#define HTF_LOG_H

#include <htf_base.h>
#include <htf_guard.h>
#include <htf_result.h>
#include <stdarg.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>

#define HTF_LOG_WARN_ENABLED 1
#define HTF_LOG_INFO_ENABLED 1
#define HTF_LOG_DEBUG_ENABLED 1
#define HTF_LOG_TRACE_ENABLED 1

typedef enum HTFLogLevel {
	HTF_LOG_LEVEL_FATAL = 0,
	HTF_LOG_LEVEL_ERROR = 1,
	HTF_LOG_LEVEL_WARN = 2,
	HTF_LOG_LEVEL_INFO = 3,
	HTF_LOG_LEVEL_DEBUG = 4,
	HTF_LOG_LEVEL_TRACE = 5,
} HTFLogLevel;

static const char *HTF_LOG_LEVEL_STR[6] = {
	"FATAL",
	"ERROR",
	"WARN",
	"INFO",
	"DEBUG",
	"TRACE",
};

static inline Result htf_log_write(HTFLogLevel level, const char * const file, i32 line, const char * const func, const char * const fmt, ...)
{
	Result ret = RESULT(TYPE_VOID, NULL, ERROR_CODE_SENTINEL, "SENTINEL");

    // Get current time with microsecond precision
    struct tm *tm_info = NULL;
    const char *level_str = NULL;
    struct timeval tv = {0};
    char time_str[32] = {0};
    va_list args = {0};

	GUARD_BOUNDS(level, HTF_LOG_LEVEL_FATAL, HTF_LOG_LEVEL_TRACE, TYPE_VOID, "invalid log level in htf_log_write");
	GUARD_NULL(file, TYPE_VOID, "file is NULL in htf_log_write");
	GUARD_NULL(func, TYPE_VOID, "func is NULL in htf_log_write");
	GUARD_NULL(fmt, TYPE_VOID, "fmt is NULL in htf_log_write");

    gettimeofday(&tv, NULL);
    tm_info = localtime(&tv.tv_sec);
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", tm_info);
    snprintf(time_str + 19, sizeof(time_str) - 19, ".%06ld", tv.tv_usec);
	level_str = HTF_LOG_LEVEL_STR[level];

    // Print log header
    fprintf(stderr, "[%s] [%s] [%s:%d] [%s] ", time_str, level_str, file, line, func);

    // Print log message
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);
    fprintf(stderr, "\n");

	ret = RESULT(TYPE_VOID, NULL, ERROR_CODE_NONE, "NONE");
cleanup:
	return ret;
}
#define HTF_LOG_FATAL(...) htf_log_write(HTF_LOG_LEVEL_FATAL, __FILE__, __LINE__, __func__, __VA_ARGS__)
#define HTF_LOG_ERROR(...) htf_log_write(HTF_LOG_LEVEL_ERROR, __FILE__, __LINE__, __func__, __VA_ARGS__)
#define HTF_LOG_WARN(...)  htf_log_write(HTF_LOG_LEVEL_WARN,  __FILE__, __LINE__, __func__, __VA_ARGS__)
#define HTF_LOG_INFO(...)  htf_log_write(HTF_LOG_LEVEL_INFO,  __FILE__, __LINE__, __func__, __VA_ARGS__)
#define HTF_LOG_DEBUG(...) htf_log_write(HTF_LOG_LEVEL_DEBUG, __FILE__, __LINE__, __func__, __VA_ARGS__)
#define HTF_LOG_TRACE(...) htf_log_write(HTF_LOG_LEVEL_TRACE, __FILE__, __LINE__, __func__, __VA_ARGS__)

#endif

#ifndef HTF_LOG_H
#define HTF_LOG_H

#include <htf_base.h>
#include <htf_guard.h>
#include <htf_result.h>
#include <stdarg.h>
#include <stdio.h>

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

Result_void htf_log_write(HTFLogLevel level, const char * const file, i32 line, const char * const func, const char * const fmt, ...)
{
	Result_void ret = Err_void("unknown error in htf_log_write");
	va_list args = {0};

	GUARD_BOUNDS(level, HTF_LOG_LEVEL_FATAL, HTF_LOG_LEVEL_TRACE, void, "level passed to htf_log_write is out of bounds");
	GUARD_NULL(file, void, "file passed to htf_log_write is NULL");
	GUARD_NON_POS(line, void, "line passed to htf_log_write is non-positive");
	GUARD_NULL(func, void, "func passed to htf_log_write is NULL");
	GUARD_NULL(fmt, void, "fmt passed to htf_log_write is NULL");

	va_start(args, fmt);
	vprintf(fmt, args);
	va_end(args);

	fprintf(stdout, "%s:%d %s: ", file, line, func);
	vprintf(fmt, args);
	fprintf(stdout, "\n");

	ret = Ok_void((VOID){0});
cleanup:
	return ret;
}
#define HTF_LOG_FATAL(...) htf_log_write(HTF_LOG_FATAL, __FILE__, __LINE__, __func__, __VA_ARGS__)
#define HTF_LOG_ERROR(...) htf_log_write(HTF_LOG_ERROR, __FILE__, __LINE__, __func__, __VA_ARGS__)
#define HTF_LOG_WARN(...)  htf_log_write(HTF_LOG_WARN,  __FILE__, __LINE__, __func__, __VA_ARGS__)
#define HTF_LOG_INFO(...)  htf_log_write(HTF_LOG_INFO,  __FILE__, __LINE__, __func__, __VA_ARGS__)
#define HTF_LOG_DEBUG(...) htf_log_write(HTF_LOG_DEBUG, __FILE__, __LINE__, __func__, __VA_ARGS__)
#define HTF_LOG_TRACE(...) htf_log_write(HTF_LOG_TRACE, __FILE__, __LINE__, __func__, __VA_ARGS__)

#endif

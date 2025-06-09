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

Result_void htf_log_write(HTFLogLevel level, const char * const file, i32 line, const char * const func, const char * const fmt, ...);
#define HTF_LOG_FATAL(...) htf_log_write(HTF_LOG_LEVEL_FATAL, __FILE__, __LINE__, __func__, __VA_ARGS__)
#define HTF_LOG_ERROR(...) htf_log_write(HTF_LOG_LEVEL_ERROR, __FILE__, __LINE__, __func__, __VA_ARGS__)
#define HTF_LOG_WARN(...)  htf_log_write(HTF_LOG_LEVEL_WARN,  __FILE__, __LINE__, __func__, __VA_ARGS__)
#define HTF_LOG_INFO(...)  htf_log_write(HTF_LOG_LEVEL_INFO,  __FILE__, __LINE__, __func__, __VA_ARGS__)
#define HTF_LOG_DEBUG(...) htf_log_write(HTF_LOG_LEVEL_DEBUG, __FILE__, __LINE__, __func__, __VA_ARGS__)
#define HTF_LOG_TRACE(...) htf_log_write(HTF_LOG_LEVEL_TRACE, __FILE__, __LINE__, __func__, __VA_ARGS__)

#endif

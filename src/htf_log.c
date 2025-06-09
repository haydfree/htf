#include <htf_log.h>

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

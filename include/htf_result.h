#ifndef HTF_RESULT_H
#define HTF_RESULT_H

#include <htf_assert.h>
#include <htf_base.h>
#include <htf_error.h>

typedef struct Result
{
	void *ok;
	Error error;
} Result;

static inline Result htf_result_ok(Type type, void *val, ErrorCode code, const char *msg)
{
	Result result = {0};
	result.ok = val;
	result.error = ERROR(ERROR_CODE_NONE, "NONE");
	return result;
}

static inline Result htf_result_err(Type type, void *val, ErrorCode code, const char *msg)
{
	Result result = {0};
	result.ok = OPTION();
	result.error = ERROR(code, msg);
	return result;
}

#define RESULT(type, val, code, msg) do { if (code == ERROR_CODE_NONE) { htf_result_ok(type, val, code, msg); } else { htf_result_err(type, val, code, msg); } } while (0)

#endif

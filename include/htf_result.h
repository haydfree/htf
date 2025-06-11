#ifndef HTF_RESULT_H
#define HTF_RESULT_H

#include <htf_assert.h>
#include <htf_base.h>
#include <htf_error.h>

typedef struct Result
{
	void *ok;
	Error error;
	Type type;
} Result;

static inline Result htf_result_ok(Type type, void *val)
{
	Result result = {0};
	result.ok = val;
	result.error = ERROR(ERROR_CODE_NONE, "NONE");
	result.type = type;
	return result;
}

static inline Result htf_result_err(Type type, ErrorCode code, const char *msg)
{
	Result result = {0};
	result.ok = NULL;
	result.error = ERROR(code, msg);
	result.type = type;
	return result;
}

#define RESULT(type, val, code, msg) (code == ERROR_CODE_NONE ? htf_result_ok(type, val) : htf_result_err(type, code, msg))

#endif

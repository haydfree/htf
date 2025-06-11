#ifndef HTF_ERROR_H
#define HTF_ERROR_H

#include <htf_base.h>
#include <string.h>

#define MAX_ERROR_MSG_LEN 256

typedef enum ErrorCode
{
	ERROR_CODE_NONE = 0,
	ERROR_CODE_BOUNDS = 1,
	ERROR_CODE_TRUE = 2,
	ERROR_CODE_FALSE = 3,
	ERROR_CODE_NULL = 4,
	ERROR_CODE_POS = 5,
	ERROR_CODE_NEG = 6,
	ERROR_CODE_ZERO = 7,
	ERROR_CODE_NON_NULL = 8,
	ERROR_CODE_NON_POS = 9,
	ERROR_CODE_NON_NEG = 10,
	ERROR_CODE_NON_ZERO = 11,
	ERROR_CODE_EQ = 12,
	ERROR_CODE_NEQ = 13,
	ERROR_CODE_GT = 14,
	ERROR_CODE_GTE = 15,
	ERROR_CODE_LT = 16,
	ERROR_CODE_LTE = 17,
	ERROR_CODE_SENTINEL = -1,
	ERROR_CODE_UNKNOWN = 69,
} ErrorCode;

typedef struct Error
{
	ErrorCode code;
	char msg[MAX_ERROR_MSG_LEN];
} Error;

static inline Error htf_error(ErrorCode code, const char *msg)
{
	Error error = {0};
	error.code = code;
	strncpy(error.msg, msg, MAX_ERROR_MSG_LEN - 1);
	error.msg[MAX_ERROR_MSG_LEN - 1] = '\0';
	return error;
}

#define ERROR(code, msg) htf_error(code, msg)

#endif

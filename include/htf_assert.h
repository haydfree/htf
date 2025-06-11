#ifndef HTF_ASSERT_H
#define HTF_ASSERT_H

#include <htf_log.h>
#include <htf_sys.h>

#define DEBUG_BREAK() __builtin_trap()

#define HTF_ASSERT(expr, fmt, ...) do { if (!(expr)) \
{ \
	HTF_LOG_ERROR(fmt, __VA_ARGS__); \
	DEBUG_BREAK(); \
	EXIT(1); \
} } while (0)

#define HTF_ASSERT_TRUE(expr, fmt, ...) HTF_ASSERT(expr, fmt, __VA_ARGS__)
#define HTF_ASSERT_FALSE(expr, fmt, ...) HTF_ASSERT(!(expr), fmt, __VA_ARGS__)
#define HTF_ASSERT_EQ(a, b, fmt, ...) HTF_ASSERT((a) == (b), fmt, __VA_ARGS__)
#define HTF_ASSERT_NE(a, b, fmt, ...) HTF_ASSERT((a) != (b), fmt, __VA_ARGS__)
#define HTF_ASSERT_LT(a, b, fmt, ...) HTF_ASSERT((a) < (b), fmt, __VA_ARGS__)
#define HTF_ASSERT_LE(a, b, fmt, ...) HTF_ASSERT((a) <= (b), fmt, __VA_ARGS__)
#define HTF_ASSERT_GT(a, b, fmt, ...) HTF_ASSERT((a) > (b), fmt, __VA_ARGS__)
#define HTF_ASSERT_GE(a, b, fmt, ...) HTF_ASSERT((a) >= (b), fmt, __VA_ARGS__)

#endif

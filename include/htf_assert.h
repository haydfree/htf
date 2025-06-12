#ifndef HTF_ASSERT_H
#define HTF_ASSERT_H

#include <htf_log.h>
#include <htf_sys.h>

#define DEBUG_BREAK() __builtin_trap()

#define HTF_ASSERT_EXPR(expr) do { if (!(expr)) \
{ \
	HTF_LOG_ERROR("Assertion failed: ( %s ) == %s", #expr, (expr) ? "true" : "false"); \
	DEBUG_BREAK(); \
	EXIT(1); \
} } while (0)

#define HTF_ASSERT(type, expr, a, b) do { if (!(expr)) \
{ \
	HTF_LOG_ERROR("Assertion failed: ( %s ) == %s. Actual: %s, Expected: %s", #expr, (expr) ? "true" : "false", a, b); \
	DEBUG_BREAK(); \
	EXIT(1); \
} } while (0)

#define HTF_ASSERT_TRUE(expr) HTF_ASSERT_EXPR(expr)
#define HTF_ASSERT_FALSE(expr) HTF_ASSERT_EXPR(!(expr))
#define HTF_ASSERT_EQ(type, a, b) HTF_ASSERT(type, (a) == (b), a, b)
#define HTF_ASSERT_NE(type, a, b) HTF_ASSERT(type, (a) != (b), a, b)
#define HTF_ASSERT_LT(type, a, b) HTF_ASSERT(type, (a) < (b), a, b)
#define HTF_ASSERT_LE(type, a, b) HTF_ASSERT(type, (a) <= (b), a, b)
#define HTF_ASSERT_GT(type, a, b) HTF_ASSERT(type, (a) > (b), a, b)
#define HTF_ASSERT_GE(type, a, b) HTF_ASSERT(type, (a) >= (b), a, b)

#endif

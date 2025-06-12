#ifndef HTF_ASSERT_H
#define HTF_ASSERT_H

#include <htf_log.h>

#define DEBUG_BREAK() __builtin_trap()

#define HTF_ASSERT_BASE(type, expr, a, b, fmt) do { \
    if (!(expr)) { \
        HTF_LOG_ERROR("Assertion failed: ( %s ) == %s. Actual: " fmt ", Expected: " fmt, \
            #expr, (expr) ? "true" : "false", (type)(a), (type)(b)); \
        DEBUG_BREAK(); \
        EXIT(1); \
    } \
} while (0)

#define HTF_ASSERT_U8(expr, a, b) HTF_ASSERT_BASE(u8, expr, a, b, "%u")
#define HTF_ASSERT_U16(expr, a, b) HTF_ASSERT_BASE(u16, expr, a, b, "%u")
#define HTF_ASSERT_U32(expr, a, b) HTF_ASSERT_BASE(u32, expr, a, b, "%u")
#define HTF_ASSERT_U64(expr, a, b) HTF_ASSERT_BASE(u64, expr, a, b, "%llu")
#define HTF_ASSERT_I8(expr, a, b) HTF_ASSERT_BASE(i8, expr, a, b, "%d")
#define HTF_ASSERT_I16(expr, a, b) HTF_ASSERT_BASE(i16, expr, a, b, "%d")
#define HTF_ASSERT_I32(expr, a, b) HTF_ASSERT_BASE(i32, expr, a, b, "%d")
#define HTF_ASSERT_I64(expr, a, b) HTF_ASSERT_BASE(i64, expr, a, b, "%lld")
#define HTF_ASSERT_F32(expr, a, b) HTF_ASSERT_BASE(f32, expr, a, b, "%f")
#define HTF_ASSERT_F64(expr, a, b) HTF_ASSERT_BASE(f64, expr, a, b, "%lf")
#define HTF_ASSERT_B8(expr, a, b) HTF_ASSERT_BASE(b8, expr, a, b, "%u")
#define HTF_ASSERT_B16(expr, a, b) HTF_ASSERT_BASE(b16, expr, a, b, "%u")
#define HTF_ASSERT_B32(expr, a, b) HTF_ASSERT_BASE(b32, expr, a, b, "%u")
#define HTF_ASSERT_B64(expr, a, b) HTF_ASSERT_BASE(b64, expr, a, b, "%llu")

#define HTF_ASSERT_EQ_U8(a, b) HTF_ASSERT_U8((a) == (b), a, b)
#define HTF_ASSERT_NE_U8(a, b) HTF_ASSERT_U8((a) != (b), a, b)
#define HTF_ASSERT_LT_U8(a, b) HTF_ASSERT_U8((a) < (b), a, b)
#define HTF_ASSERT_LE_U8(a, b) HTF_ASSERT_U8((a) <= (b), a, b)
#define HTF_ASSERT_GT_U8(a, b) HTF_ASSERT_U8((a) > (b), a, b)
#define HTF_ASSERT_GE_U8(a, b) HTF_ASSERT_U8((a) >= (b), a, b)

#define HTF_ASSERT_EQ_U16(a, b) HTF_ASSERT_U16((a) == (b), a, b)
#define HTF_ASSERT_NE_U16(a, b) HTF_ASSERT_U16((a) != (b), a, b)
#define HTF_ASSERT_LT_U16(a, b) HTF_ASSERT_U16((a) < (b), a, b)
#define HTF_ASSERT_LE_U16(a, b) HTF_ASSERT_U16((a) <= (b), a, b)
#define HTF_ASSERT_GT_U16(a, b) HTF_ASSERT_U16((a) > (b), a, b)
#define HTF_ASSERT_GE_U16(a, b) HTF_ASSERT_U16((a) >= (b), a, b)

#define HTF_ASSERT_EQ_U32(a, b) HTF_ASSERT_U32((a) == (b), a, b)
#define HTF_ASSERT_NE_U32(a, b) HTF_ASSERT_U32((a) != (b), a, b)
#define HTF_ASSERT_LT_U32(a, b) HTF_ASSERT_U32((a) < (b), a, b)
#define HTF_ASSERT_LE_U32(a, b) HTF_ASSERT_U32((a) <= (b), a, b)
#define HTF_ASSERT_GT_U32(a, b) HTF_ASSERT_U32((a) > (b), a, b)
#define HTF_ASSERT_GE_U32(a, b) HTF_ASSERT_U32((a) >= (b), a, b)

#define HTF_ASSERT_EQ_U64(a, b) HTF_ASSERT_U64((a) == (b), a, b)
#define HTF_ASSERT_NE_U64(a, b) HTF_ASSERT_U64((a) != (b), a, b)
#define HTF_ASSERT_LT_U64(a, b) HTF_ASSERT_U64((a) < (b), a, b)
#define HTF_ASSERT_LE_U64(a, b) HTF_ASSERT_U64((a) <= (b), a, b)
#define HTF_ASSERT_GT_U64(a, b) HTF_ASSERT_U64((a) > (b), a, b)
#define HTF_ASSERT_GE_U64(a, b) HTF_ASSERT_U64((a) >= (b), a, b)

#define HTF_ASSERT_EQ_I8(a, b) HTF_ASSERT_I8((a) == (b), a, b)
#define HTF_ASSERT_NE_I8(a, b) HTF_ASSERT_I8((a) != (b), a, b)
#define HTF_ASSERT_LT_I8(a, b) HTF_ASSERT_I8((a) < (b), a, b)
#define HTF_ASSERT_LE_I8(a, b) HTF_ASSERT_I8((a) <= (b), a, b)
#define HTF_ASSERT_GT_I8(a, b) HTF_ASSERT_I8((a) > (b), a, b)
#define HTF_ASSERT_GE_I8(a, b) HTF_ASSERT_I8((a) >= (b), a, b)

#define HTF_ASSERT_EQ_I16(a, b) HTF_ASSERT_I16((a) == (b), a, b)
#define HTF_ASSERT_NE_I16(a, b) HTF_ASSERT_I16((a) != (b), a, b)
#define HTF_ASSERT_LT_I16(a, b) HTF_ASSERT_I16((a) < (b), a, b)
#define HTF_ASSERT_LE_I16(a, b) HTF_ASSERT_I16((a) <= (b), a, b)
#define HTF_ASSERT_GT_I16(a, b) HTF_ASSERT_I16((a) > (b), a, b)
#define HTF_ASSERT_GE_I16(a, b) HTF_ASSERT_I16((a) >= (b), a, b)

#define HTF_ASSERT_EQ_I32(a, b) HTF_ASSERT_I32((a) == (b), a, b)
#define HTF_ASSERT_NE_I32(a, b) HTF_ASSERT_I32((a) != (b), a, b)
#define HTF_ASSERT_LT_I32(a, b) HTF_ASSERT_I32((a) < (b), a, b)
#define HTF_ASSERT_LE_I32(a, b) HTF_ASSERT_I32((a) <= (b), a, b)
#define HTF_ASSERT_GT_I32(a, b) HTF_ASSERT_I32((a) > (b), a, b)
#define HTF_ASSERT_GE_I32(a, b) HTF_ASSERT_I32((a) >= (b), a, b)

#define HTF_ASSERT_EQ_I64(a, b) HTF_ASSERT_I64((a) == (b), a, b)
#define HTF_ASSERT_NE_I64(a, b) HTF_ASSERT_I64((a) != (b), a, b)
#define HTF_ASSERT_LT_I64(a, b) HTF_ASSERT_I64((a) < (b), a, b)
#define HTF_ASSERT_LE_I64(a, b) HTF_ASSERT_I64((a) <= (b), a, b)
#define HTF_ASSERT_GT_I64(a, b) HTF_ASSERT_I64((a) > (b), a, b)
#define HTF_ASSERT_GE_I64(a, b) HTF_ASSERT_I64((a) >= (b), a, b)

#define HTF_ASSERT_EQ_F32(a, b) HTF_ASSERT_F32((a) == (b), a, b)
#define HTF_ASSERT_NE_F32(a, b) HTF_ASSERT_F32((a) != (b), a, b)
#define HTF_ASSERT_LT_F32(a, b) HTF_ASSERT_F32((a) < (b), a, b)
#define HTF_ASSERT_LE_F32(a, b) HTF_ASSERT_F32((a) <= (b), a, b)
#define HTF_ASSERT_GT_F32(a, b) HTF_ASSERT_F32((a) > (b), a, b)
#define HTF_ASSERT_GE_F32(a, b) HTF_ASSERT_F32((a) >= (b), a, b)

#define HTF_ASSERT_EQ_F64(a, b) HTF_ASSERT_F64((a) == (b), a, b)
#define HTF_ASSERT_NE_F64(a, b) HTF_ASSERT_F64((a) != (b), a, b)
#define HTF_ASSERT_LT_F64(a, b) HTF_ASSERT_F64((a) < (b), a, b)
#define HTF_ASSERT_LE_F64(a, b) HTF_ASSERT_F64((a) <= (b), a, b)
#define HTF_ASSERT_GT_F64(a, b) HTF_ASSERT_F64((a) > (b), a, b)
#define HTF_ASSERT_GE_F64(a, b) HTF_ASSERT_F64((a) >= (b), a, b)

#define HTF_ASSERT_EQ_B8(a, b) HTF_ASSERT_B8((a) == (b), a, b)
#define HTF_ASSERT_NE_B8(a, b) HTF_ASSERT_B8((a) != (b), a, b)
#define HTF_ASSERT_LT_B8(a, b) HTF_ASSERT_B8((a) < (b), a, b)
#define HTF_ASSERT_LE_B8(a, b) HTF_ASSERT_B8((a) <= (b), a, b)
#define HTF_ASSERT_GT_B8(a, b) HTF_ASSERT_B8((a) > (b), a, b)
#define HTF_ASSERT_GE_B8(a, b) HTF_ASSERT_B8((a) >= (b), a, b)

#define HTF_ASSERT_EQ_B16(a, b) HTF_ASSERT_B16((a) == (b), a, b)
#define HTF_ASSERT_NE_B16(a, b) HTF_ASSERT_B16((a) != (b), a, b)
#define HTF_ASSERT_LT_B16(a, b) HTF_ASSERT_B16((a) < (b), a, b)
#define HTF_ASSERT_LE_B16(a, b) HTF_ASSERT_B16((a) <= (b), a, b)
#define HTF_ASSERT_GT_B16(a, b) HTF_ASSERT_B16((a) > (b), a, b)
#define HTF_ASSERT_GE_B16(a, b) HTF_ASSERT_B16((a) >= (b), a, b)

#define HTF_ASSERT_EQ_B32(a, b) HTF_ASSERT_B32((a) == (b), a, b)
#define HTF_ASSERT_NE_B32(a, b) HTF_ASSERT_B32((a) != (b), a, b)
#define HTF_ASSERT_LT_B32(a, b) HTF_ASSERT_B32((a) < (b), a, b)
#define HTF_ASSERT_LE_B32(a, b) HTF_ASSERT_B32((a) <= (b), a, b)
#define HTF_ASSERT_GT_B32(a, b) HTF_ASSERT_B32((a) > (b), a, b)
#define HTF_ASSERT_GE_B32(a, b) HTF_ASSERT_B32((a) >= (b), a, b)

#define HTF_ASSERT_EQ_B64(a, b) HTF_ASSERT_B64((a) == (b), a, b)
#define HTF_ASSERT_NE_B64(a, b) HTF_ASSERT_B64((a) != (b), a, b)
#define HTF_ASSERT_LT_B64(a, b) HTF_ASSERT_B64((a) < (b), a, b)
#define HTF_ASSERT_LE_B64(a, b) HTF_ASSERT_B64((a) <= (b), a, b)
#define HTF_ASSERT_GT_B64(a, b) HTF_ASSERT_B64((a) > (b), a, b)
#define HTF_ASSERT_GE_B64(a, b) HTF_ASSERT_B64((a) >= (b), a, b)

#define HTF_ASSERT_TRUE(expr) do { \
    if (!(expr)) { \
        HTF_LOG_ERROR("Assertion failed: ( %s ) == true", #expr); \
        DEBUG_BREAK(); \
        EXIT(1); \
    } \
} while (0)

#define HTF_ASSERT_FALSE(expr) do { \
    if (expr) { \
        HTF_LOG_ERROR("Assertion failed: ( %s ) == false", #expr); \
        DEBUG_BREAK(); \
        EXIT(1); \
    } \
} while (0)

#endif

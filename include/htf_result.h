#ifndef HTF_RESULT_H
#define HTF_RESULT_H

#include <htf_base.h>

#define DEFINE_RESULT(ok_type, err_type, name)           \
    typedef enum                                         \
    {                                                    \
        RESULT_OK_##name,                                \
        RESULT_ERR_##name                                \
    } ResultTag_##name;                                  \
                                                         \
    typedef struct                                       \
    {                                                    \
        ResultTag_##name tag;                            \
        union                                            \
        {                                                \
            ok_type ok;                                  \
            err_type err;                                \
        } data;                                          \
    } Result_##name;                                     \
                                                         \
    inline Result_##name Ok_##name(ok_type val)   		 \
    {                                                    \
        Result_##name r = { .tag = RESULT_OK_##name };   \
        r.data.ok = val;                                 \
        return r;                                        \
    }                                                    \
                                                         \
    inline Result_##name Err_##name(err_type val) 		 \
    {                                                    \
        Result_##name r = { .tag = RESULT_ERR_##name };  \
        r.data.err = val;                                \
        return r;                                        \
    }                                                    \
                                                         \
    inline int is_ok_##name(Result_##name res)    		 \
    {                                                    \
        return res.tag == RESULT_OK_##name;              \
    }                                                    \
                                                         \
    inline int is_err_##name(Result_##name res)   		 \
    {                                                    \
        return res.tag == RESULT_ERR_##name;             \
    }

DEFINE_RESULT(u8, const char *, u8)
DEFINE_RESULT(u16, const char *, u16)
DEFINE_RESULT(u32, const char *, u32)
DEFINE_RESULT(u64, const char *, u64)
DEFINE_RESULT(i8, const char *, i8)
DEFINE_RESULT(i16, const char *, i16)
DEFINE_RESULT(i32, const char *, i32)
DEFINE_RESULT(i64, const char *, i64)
DEFINE_RESULT(f32, const char *, f32)
DEFINE_RESULT(f64, const char *, f64)
DEFINE_RESULT(b8, const char *, b8)
DEFINE_RESULT(b16, const char *, b16)
DEFINE_RESULT(b32, const char *, b32)
DEFINE_RESULT(b64, const char *, b64)
DEFINE_RESULT(VOID, const char *, void)

#endif

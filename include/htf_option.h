#ifndef HTF_OPTION_H
#define HTF_OPTION_H

#include <htf_base.h>

#define DEFINE_OPTION(type, name)                                \
    typedef enum                                                 \
    {                                                            \
        OPTION_NONE_##name,                                      \
        OPTION_SOME_##name                                       \
    } OptionTag_##name;                                          \
                                                                 \
    typedef struct                                               \
    {                                                            \
        OptionTag_##name tag;                                    \
        type value;                                              \
    } Option_##name;                                             \
                                                                 \
    inline Option_##name Some_##name(type val)            		 \
    {                                                            \
        return (Option_##name){ OPTION_SOME_##name, (type)val }; \
    }                                                            \
                                                                 \
    inline Option_##name None_##name(void)                		 \
    {                                                            \
        return (Option_##name){ OPTION_NONE_##name, (type){0} }; \
    }                                                            \
                                                                 \
    inline int is_some_##name(Option_##name opt)          		 \
    {                                                            \
        return opt.tag == OPTION_SOME_##name;                    \
    }                                                            \
                                                                 \
    inline int is_none_##name(Option_##name opt)         		 \
    {                                                            \
        return opt.tag == OPTION_NONE_##name;                    \
    }

DEFINE_OPTION(u8, u8)
DEFINE_OPTION(u16, u16)
DEFINE_OPTION(u32, u32)
DEFINE_OPTION(u64, u64)
DEFINE_OPTION(i8, i8)
DEFINE_OPTION(i16, i16)
DEFINE_OPTION(i32, i32)
DEFINE_OPTION(i64, i64)
DEFINE_OPTION(f32, f32)
DEFINE_OPTION(f64, f64)
DEFINE_OPTION(b8, b8)
DEFINE_OPTION(b16, b16)
DEFINE_OPTION(b32, b32)
DEFINE_OPTION(b64, b64)

#endif

#ifndef HTF_RESULT_H
#define HTF_RESULT_H

#include <htf_assert.h>
#include <htf_base.h>

#define DEFINE_RESULT_TYPE(Name, OkType, ErrType)    	\
    typedef enum { Name##_OK, Name##_ERR } Name##_Tag; 	\
    typedef struct 										\
	{                                 					\
        Name##_Tag tag;                              	\
        union											\ 
		{                                      			\
            OkType ok;                               	\
            ErrType err;                             	\
        } value;                                     	\
    } Name;												\
	inline Name Name##_ok(OkType value) 				\
	{													\
		Name result = {0};								\
		result.tag = Name##_OK;							\
		result.value.ok = value;						\
		return result;									\
	}													\
	inline Name Name##_err(ErrType value) 				\
	{													\
		Name result = {0};								\
		result.tag = Name##_ERR;						\
		result.value.err = value;						\
		return result;									\
	}													\
	inline b8 Name##_is_ok(Name result) 				\
	{													\
		return result.tag == Name##_OK;					\
	}													\
	inline b8 Name##_is_err(Name result) 				\
	{													\
		return result.tag == Name##_ERR;				\
	}													\
	inline OkType Name##_unwrap(Name result) 			\
	{													\
		return result.value.ok;							\
	}													\

DEFINE_RESULT_TYPE(Result_u8, u8, const char *)
DEFINE_RESULT_TYPE(Result_u16, u16, const char *)
DEFINE_RESULT_TYPE(Result_u32, u32, const char *)
DEFINE_RESULT_TYPE(Result_u64, u64, const char *)
DEFINE_RESULT_TYPE(Result_i8, i8, const char *)
DEFINE_RESULT_TYPE(Result_i16, i16, const char *)
DEFINE_RESULT_TYPE(Result_i32, i32, const char *)
DEFINE_RESULT_TYPE(Result_i64, i64, const char *)
DEFINE_RESULT_TYPE(Result_f32, f32, const char *)
DEFINE_RESULT_TYPE(Result_f64, f64, const char *)
DEFINE_RESULT_TYPE(Result_b8, b8, const char *)
DEFINE_RESULT_TYPE(Result_b16, b16, const char *)
DEFINE_RESULT_TYPE(Result_b32, b32, const char *)
DEFINE_RESULT_TYPE(Result_b64, b64, const char *)

#endif

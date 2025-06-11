#ifndef HTF_BASE_H
#define HTF_BASE_H

#include <htf_assert.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE -1
#define TRUE ((b8)1)
#define FALSE ((b8)0)
#define NULL ((void*)0)

#define u8 unsigned char
#define u16 unsigned short
#define u32 unsigned int
#define u64 unsigned long long

#define i8 signed char
#define i16 signed short
#define i32 signed int
#define i64 signed long long

#define f32 float
#define f64 double

#define b8 u8
#define b16 u16
#define b32 u32
#define b64 u64

STATIC_ASSERT(sizeof(u8) == 1,  u8_must_be_1_byte);
STATIC_ASSERT(sizeof(u16) == 2, u16_must_be_2_bytes);
STATIC_ASSERT(sizeof(u32) == 4, u32_must_be_4_bytes);
STATIC_ASSERT(sizeof(u64) == 8, u64_must_be_8_bytes);
STATIC_ASSERT(sizeof(i8) == 1,  i8_must_be_1_byte);
STATIC_ASSERT(sizeof(i16) == 2, i16_must_be_2_bytes);
STATIC_ASSERT(sizeof(i32) == 4, i32_must_be_4_bytes);
STATIC_ASSERT(sizeof(i64) == 8, i64_must_be_8_bytes);
STATIC_ASSERT(sizeof(f32) == 4, f32_must_be_4_bytes);
STATIC_ASSERT(sizeof(f64) == 8, f64_must_be_8_bytes);
STATIC_ASSERT(sizeof(b8) == 1,  b8_must_be_1_byte);
STATIC_ASSERT(sizeof(b16) == 2, b16_must_be_2_bytes);
STATIC_ASSERT(sizeof(b32) == 4, b32_must_be_4_bytes);
STATIC_ASSERT(sizeof(b64) == 8, b64_must_be_8_bytes);

typedef struct { u8 _0; } VOID;

typedef enum Type
{
	TYPE_U8 = 0,
	TYPE_U16 = 1,
	TYPE_U32 = 2,
	TYPE_U64 = 3,
	TYPE_I8 = 4,
	TYPE_I16 = 5,
	TYPE_I32 = 6,
	TYPE_I64 = 7,
	TYPE_F32 = 8,
	TYPE_F64 = 9,
	TYPE_B8 = 10,
	TYPE_B16 = 11,
	TYPE_B32 = 12,
	TYPE_B64 = 13,
	TYPE_VOID = 14,
} Type;

#endif

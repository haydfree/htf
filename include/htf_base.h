#ifndef HTF_BASE_H
#define HTF_BASE_H

#define STATIC_ASSERT(expr, msg) typedef char static_assert_##msg[expr ? 1 : -1]

#define EXIT_SUCCESS 0
#define EXIT_FAILURE -1
#define TRUE ((b8)1)
#define FALSE ((b8)0)
#define NULL ((void*)0)
typedef struct { unsigned char _0; } VOID;

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

typedef enum Type
{
	TYPE_u8 = 0,
	TYPE_u16 = 1,
	TYPE_u32 = 2,
	TYPE_u64 = 3,
	TYPE_i8 = 4,
	TYPE_i16 = 5,
	TYPE_i32 = 6,
	TYPE_i64 = 7,
	TYPE_f32 = 8,
	TYPE_f64 = 9,
	TYPE_b8 = 10,
	TYPE_b16 = 11,
	TYPE_b32 = 12,
	TYPE_b64 = 13,
	TYPE_void = 90,
	TYPE_int = 91,
	TYPE_result = 92,
} Type;

#endif

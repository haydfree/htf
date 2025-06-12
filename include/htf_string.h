#ifndef HTF_STRING_H
#define HTF_STRING_H

#include <htf_base.h>
#include <stdio.h>

static inline char *htf_string_format_value(Type type, void *value, char * const dst)
{
	switch (type)
	{
		case TYPE_u8:
			snprintf(dst, sizeof(dst), "%u", *(u8*)value);
			break;
		case TYPE_u16:
			snprintf(dst, sizeof(dst), "%u", *(u16*)value);
			break;
		case TYPE_u32:
			snprintf(dst, sizeof(dst), "%u", *(u32*)value);
			break;
		case TYPE_u64:
			snprintf(dst, sizeof(dst), "%llu", *(u64*)value);
			break;
		case TYPE_i8:
			snprintf(dst, sizeof(dst), "%d", *(i8*)value);
			break;
		case TYPE_i16:
			snprintf(dst, sizeof(dst), "%d", *(i16*)value);
			break;
		case TYPE_i32:
			snprintf(dst, sizeof(dst), "%d", *(i32*)value);
			break;
		case TYPE_i64:
			snprintf(dst, sizeof(dst), "%lld", *(i64*)value);
			break;
		case TYPE_f32:
			snprintf(dst, sizeof(dst), "%f", *(f32*)value);
			break;
		case TYPE_f64:
			snprintf(dst, sizeof(dst), "%lf", *(f64*)value);
			break;
		case TYPE_b8:
			snprintf(dst, sizeof(dst), "%u", *(b8*)value);
			break;
		case TYPE_b16:
			snprintf(dst, sizeof(dst), "%u", *(b16*)value);
			break;
		case TYPE_b32:
			snprintf(dst, sizeof(dst), "%u", *(b32*)value);
			break;
		case TYPE_b64:
			snprintf(dst, sizeof(dst), "%llu", *(b64*)value);
			break;
		default:
			snprintf(dst, sizeof(dst), "unknown type: %d", type);
			break;
	}
}

#define HTF_STRING_FORMAT_VALUE(type, value, dst) htf_string_format_value(type, (void*)value, dst)

#endif

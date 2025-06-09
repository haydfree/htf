#include <htf_memory.h>

inline Result_void
htf_zero_memory(void *ptr, u64 size) 
{
	Result_void ret = Err_void("unknown error in htf_zero_memory");
	u8 *p = (u8*)NULL;
	u64 i = 0;

	GUARD_NULL(ptr, void, "ptr passed to htf_zero_memory is NULL");
	GUARD_NON_POS(size, void, "size passed to htf_zero_memory is non-positive");

	p = (u8*)ptr;
	for (; i < size; i++) { p[i] = 0; }

	ret = Ok_void((VOID){0});
cleanup:
	return ret;
}

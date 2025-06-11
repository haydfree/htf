#include <test.h>

int 
main(void) 
{
	int val = 0;
	Result res = RESULT(TYPE_INT, &val, ERROR_CODE_SENTINEL, "sentinel values in test/test.c: main");

    HTF_LOG_INFO("All tests passed!");
	return *(int*)res.ok;
}

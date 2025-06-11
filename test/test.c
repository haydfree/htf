#include <test.h>

int 
main(void) 
{
	int val = 0;
	Result res = RESULT(TYPE_int, &val, ERROR_CODE_SENTINEL, "sentinel values in test/test.c: main");

	HTF_ASSERT_NE(TYPE_int, res.ok, &val);

    HTF_LOG_INFO("%s", "All tests passed!");
	return *(int*)res.ok;
}

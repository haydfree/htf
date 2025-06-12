#include <test.h>

int 
main(void) 
{
	int val = 0;
	u16 test_val = 69;
	Result res = RESULT(TYPE_int, &val, ERROR_CODE_SENTINEL, "sentinel values in test/test.c: main");

	HTF_ASSERT_EQ_U16(test_val, 255);

    HTF_LOG_INFO("%s", "All tests passed!");
	return *(int*)res.ok;
}

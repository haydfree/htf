#include <test.h>

int 
main(void) 
{
	int val = 0;
	Result res = RESULT(TYPE_INT, &val, ERROR_CODE_SENTINEL, "sentinel values in test/test.c: main");

	HTF_ASSERT_EQ(res.ok, &val, "expected %d, got %d", val, *(int*)res.ok);

    HTF_LOG_INFO("%s", "All tests passed!");
	return *(int*)res.ok;
}

#include <test.h>

int 
main(void) 
{
	int val = 0;
	u8 u8_val = 69;
	char buf[1024] = {0};
	Result res = RESULT(TYPE_int, &val, ERROR_CODE_SENTINEL, "sentinel values in test/test.c: main");

	(void)HTF_STRING_FORMAT_VALUE(TYPE_u8, &u8_val, (char*)&buf);
	HTF_LOG_INFO("buf: %s", buf);

    HTF_LOG_INFO("%s", "All tests passed!");
	return *(int*)res.ok;
}

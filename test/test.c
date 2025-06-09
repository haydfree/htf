#include <test.h>

Result_void
main(void)
{
	Result_void ret = Err_void("unknown error in main");

	ZERO_MEMORY(NULL, 0);
	HTF_LOG_INFO("hello from test.c");

	ret = Ok_void((VOID){0});
cleanup:
	return ret;
}

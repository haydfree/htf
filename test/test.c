#include <test.h>

Result_void 
run_tests(void) 
{
	Result_void ret = Err_void("unknown error in run_tests");

    ZERO_MEMORY(NULL, 0);
    HTF_LOG_INFO("hello from test.c");

	ret = Ok_void((VOID){0});
cleanup:
	return ret;
}

int 
main(void) 
{
    Result_void result = run_tests();
    return is_ok_void(result) ? 0 : 1;
}

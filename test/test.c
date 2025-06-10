#include <test.h>

Result
run_tests(void) 
{
	Result ret = Err("unknown error in run_tests");

	HTF_LOG_INFO("hello from test.c");

	ret = Ok_void((VOID){0});
cleanup:
	return ret;
}

int 
main(void) 
{
	Result ret = Err("unknown error in run_tests");
	ret = run_tests();

	GUARD_RESULT(run_tests(), void, "unknown error in main");

    HTF_LOG_INFO("All tests passed!");
    return 0;
}

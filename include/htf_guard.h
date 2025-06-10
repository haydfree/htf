#ifndef HTF_GUARD_H
#define HTF_GUARD_H

#include <htf_base.h>
#include <htf_result.h>

#define GUARD_BOUNDS(val, min, max, type, msg) 	do { if ((val) < (min) || (val) > (max)) { ret = Err_##type((msg)); goto cleanup; } } while (0)
#define GUARD_SUCCESS(expr, type, msg) 			do { if ((expr == EXIT_SUCCESS)) { ret = Err_##type((msg)); goto cleanup; } } while (0)
#define GUARD_FAILURE(expr, type, msg) 			do { if ((expr == EXIT_FAILURE)) { ret = Err_##type((msg)); goto cleanup; } } while (0)
#define GUARD_TRUE(expr, type, msg) 			do { if ((expr == TRUE)) { ret = Err_##type((msg)); goto cleanup; } } while (0)
#define GUARD_FALSE(expr, type, msg) 			do { if ((expr == FALSE)) { ret = Err_##type((msg)); goto cleanup; } } while (0)
#define GUARD_NULL(ptr, type, msg) 				do { if ((ptr) == NULL) { ret = Err_##type((msg)); goto cleanup; } } while (0)
#define GUARD_POS(val, type, msg) 				do { if ((val) > 0) { ret = Err_##type((msg)); goto cleanup; } } while (0)
#define GUARD_NEG(val, type, msg) 				do { if ((val) < 0) { ret = Err_##type((msg)); goto cleanup; } } while (0)
#define GUARD_ZERO(val, type, msg) 				do { if ((val) == 0) { ret = Err_##type((msg)); goto cleanup; } } while (0)
#define GUARD_NON_NULL(ptr, type, msg) 			do { if ((ptr) != NULL) { ret = Err_##type((msg)); goto cleanup; } } while (0)
#define GUARD_NON_POS(val, type, msg) 			do { if ((val) <= 0) { ret = Err_##type((msg)); goto cleanup; } } while (0)
#define GUARD_NON_NEG(val, type, msg) 			do { if ((val) >= 0) { ret = Err_##type((msg)); goto cleanup; } } while (0)
#define GUARD_NON_ZERO(val, type, msg) 			do { if ((val) != 0) { ret = Err_##type((msg)); goto cleanup; } } while (0)
#define GUARD_EQ(val1, val2, type, msg) 		do { if ((val1) == (val2)) { ret = Err_##type((msg)); goto cleanup; } } while (0)
#define GUARD_NEQ(val1, val2, type, msg) 		do { if ((val1) != (val2)) { ret = Err_##type((msg)); goto cleanup; } } while (0)
#define GUARD_GT(val1, val2, type, msg) 		do { if ((val1) > (val2)) { ret = Err_##type((msg)); goto cleanup; } } while (0)
#define GUARD_GTE(val1, val2, type, msg) 		do { if ((val1) >= (val2)) { ret = Err_##type((msg)); goto cleanup; } } while (0)
#define GUARD_LT(val1, val2, type, msg) 		do { if ((val1) < (val2)) { ret = Err_##type((msg)); goto cleanup; } } while (0)
#define GUARD_LTE(val1, val2, type, msg) 		do { if ((val1) <= (val2)) { ret = Err_##type((msg)); goto cleanup; } } while (0)

#define GUARD_RESULT(result, type, msg) do { if (is_err(result, type)) { ret = expr; goto cleanup; } } while (0)

#endif

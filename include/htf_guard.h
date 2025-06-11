#ifndef HTF_GUARD_H
#define HTF_GUARD_H

#include <htf_base.h>
#include <htf_result.h>

#define GUARD_BOUNDS(val, min, max, type, msg) 	do { if ((val) < (min) || (val) > (max)) { ret = RESULT(type, &val, ERROR_CODE_BOUNDS, msg); goto cleanup; } } while (0)
#define GUARD_TRUE(expr, type, msg) 			do { if ((expr == TRUE)) { ret = RESULT(type, NULL, ERROR_CODE_TRUE, msg); goto cleanup; } } while (0)
#define GUARD_FALSE(expr, type, msg) 			do { if ((expr == FALSE)) { ret = RESULT(type, NULL, ERROR_CODE_FALSE, msg); goto cleanup; } } while (0)
#define GUARD_NULL(ptr, type, msg) 				do { if ((ptr) == NULL) { ret = RESULT(type, NULL, ERROR_CODE_NULL, msg); goto cleanup; } } while (0)
#define GUARD_POS(val, type, msg) 				do { if ((val) > 0) { ret = RESULT(type, NULL, ERROR_CODE_POS, msg); goto cleanup; } } while (0)
#define GUARD_NEG(val, type, msg) 				do { if ((val) < 0) { ret = RESULT(type, NULL, ERROR_CODE_NEG, msg); goto cleanup; } } while (0)
#define GUARD_ZERO(val, type, msg) 				do { if ((val) == 0) { ret = RESULT(type, NULL, ERROR_CODE_ZERO, msg); goto cleanup; } } while (0)
#define GUARD_NON_NULL(ptr, type, msg) 			do { if ((ptr) != NULL) { ret = RESULT(type, NULL, ERROR_CODE_NON_NULL, msg); goto cleanup; } } while (0)
#define GUARD_NON_POS(val, type, msg) 			do { if ((val) <= 0) { ret = RESULT(type, NULL, ERROR_CODE_NON_POS, msg); goto cleanup; } } while (0)
#define GUARD_NON_NEG(val, type, msg) 			do { if ((val) >= 0) { ret = RESULT(type, NULL, ERROR_CODE_NON_NEG, msg); goto cleanup; } } while (0)
#define GUARD_NON_ZERO(val, type, msg) 			do { if ((val) != 0) { ret = RESULT(type, NULL, ERROR_CODE_NON_ZERO, msg); goto cleanup; } } while (0)
#define GUARD_EQ(val1, val2, type, msg) 		do { if ((val1) == (val2)) { ret = RESULT(type, NULL, ERROR_CODE_EQ, msg); goto cleanup; } } while (0)
#define GUARD_NEQ(val1, val2, type, msg) 		do { if ((val1) != (val2)) { ret = RESULT(type, NULL, ERROR_CODE_NEQ, msg); goto cleanup; } } while (0)
#define GUARD_GT(val1, val2, type, msg) 		do { if ((val1) > (val2)) { ret = RESULT(type, NULL, ERROR_CODE_GT, msg); goto cleanup; } } while (0)
#define GUARD_GTE(val1, val2, type, msg) 		do { if ((val1) >= (val2)) { ret = RESULT(type, NULL, ERROR_CODE_GTE, msg); goto cleanup; } } while (0)
#define GUARD_LT(val1, val2, type, msg) 		do { if ((val1) < (val2)) { ret = RESULT(type, NULL, ERROR_CODE_LT, msg); goto cleanup; } } while (0)
#define GUARD_LTE(val1, val2, type, msg) 		do { if ((val1) <= (val2)) { ret = RESULT(type, NULL, ERROR_CODE_LTE, msg); goto cleanup; } } while (0)

#define GUARD_RESULT(result, type, msg) do { if (is_err(result, type)) { ret = expr; goto cleanup; } } while (0)

#endif

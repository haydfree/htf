#ifndef HTF_GUARD_H
#define HTF_GUARD_H

#include <htf_base.h>

#define GUARD_BOUNDS(val, min, max) do { if ((val) < (min) || (val) > (max)) { goto cleanup; } } while (0)
#define GUARD_SUCCESS(expr) do { if ((expr == EXIT_SUCCESS)) { goto cleanup; } } while (0)
#define GUARD_FAILURE(expr) do { if ((expr == EXIT_FAILURE)) { goto cleanup; } } while (0)
#define GUARD_TRUE(expr) do { if ((expr == TRUE)) { goto cleanup; } } while (0)
#define GUARD_FALSE(expr) do { if ((expr == FALSE)) { goto cleanup; } } while (0)
#define GUARD_NULL(ptr) do { if ((ptr) == NULL) { goto cleanup; } } while (0)
#define GUARD_POS(val) do { if ((val) > 0) { goto cleanup; } } while (0)
#define GUARD_NEG(val) do { if ((val) < 0) { goto cleanup; } } while (0)
#define GUARD_ZERO(val) do { if ((val) == 0) { goto cleanup; } } while (0)
#define GUARD_NON_NULL(ptr) do { if ((ptr) != NULL) { goto cleanup; } } while (0)
#define GUARD_NON_POS(val) do { if ((val) <= 0) { goto cleanup; } } while (0)
#define GUARD_NON_NEG(val) do { if ((val) >= 0) { goto cleanup; } } while (0)
#define GUARD_NON_ZERO(val) do { if ((val) != 0) { goto cleanup; } } while (0)
#define GUARD_EQ(val1, val2) do { if ((val1) == (val2)) { goto cleanup; } } while (0)
#define GUARD_NEQ(val1, val2) do { if ((val1) != (val2)) { goto cleanup; } } while (0)
#define GUARD_GT(val1, val2) do { if ((val1) > (val2)) { goto cleanup; } } while (0)
#define GUARD_GTE(val1, val2) do { if ((val1) >= (val2)) { goto cleanup; } } while (0)
#define GUARD_LT(val1, val2) do { if ((val1) < (val2)) { goto cleanup; } } while (0)
#define GUARD_LTE(val1, val2) do { if ((val1) <= (val2)) { goto cleanup; } } while (0)

#endif

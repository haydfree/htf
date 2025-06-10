#ifndef HTF_MEMORY_H
#define HTF_MEMORY_H

#include <htf_base.h>
#include <htf_guard.h>
#include <htf_result.h>

Result htf_zero_memory(void *ptr, u64 size);
#define ZERO_MEMORY(ptr, size) do { GUARD_RESULT(htf_zero_memory((ptr), (size)), VOID, "unknown error in ZERO_MEMORY"); } while (0)

#endif

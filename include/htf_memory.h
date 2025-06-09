#ifndef HTF_MEMORY_H
#define HTF_MEMORY_H

#include <htf_base.h>
#include <htf_guard.h>
#include <htf_result.h>

#define ZERO_MEMORY(ptr, size) do { GUARD_SUCCESS(htf_zero_memory((ptr), (size)), void, "unknown error in ZERO_MEMORY"); } while (0)

#endif

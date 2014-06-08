#pragma once

#define _CRT_ALLOCATION_DEFINED

#include <sal.h>

extern "C"
void*
__cdecl
malloc(
	__in size_t size
	);

extern "C"
void
__cdecl
free(
	__inout void* ptr
	);

extern "C"
void*
__cdecl
realloc(
	__inout_opt void* ptr,
	__in size_t size
	);

extern decltype(&malloc) cc_alloc;
extern decltype(&free) cc_free;
extern decltype(&realloc) cc_realloc;
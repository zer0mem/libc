#pragma once

#ifdef _AMD64_
#include <HeapApi.h>
#else
#include <Windows.h>
#endif

extern HANDLE gCrtHeap;

void*
__cdecl
UserMalloc(
	__in size_t size
	);

void
__cdecl
UserFree(
	__in void* mem
    );

void*
__cdecl
UserRealloc(
	__in_opt void* mem,
	__in size_t size
	);

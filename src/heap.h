#pragma once

#ifdef _AMD64_
#include <HeapApi.h>
#else
#include <Windows.h>
#endif

#include <stdio.h>

extern HANDLE gCrtHeap;
extern decltype(&vsnprintf) gMsvcrtVsnprintf;

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

int
__cdecl 
UserVsnPrintf(
	__in_ecount(count) char *buf,
	__in size_t count,
	__in const char *fmt,
	__in va_list args
	);
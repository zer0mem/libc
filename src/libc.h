#pragma once

#define _CRT_ALLOCATION_DEFINED

#include <sal.h>
#include <stdarg.h>
#include <stdio.h>

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
/*
int
__cdecl 
vsnprintf(
	__in_ecount(count) char *buf,
	__in size_t count,
	__in const char *fmt,
	__in va_list args
	);
*/
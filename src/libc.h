#pragma once

#define _CRT_ALLOCATION_DEFINED

#include <sal.h>
#include <stdarg.h>

#define _LIBC_POOL_TAG 'LIBC'

#pragma pack(push, 1)
struct MEMBLOCK
{
	size_t	size;
#pragma warning(push)               
#pragma warning (disable : 4200)
	char data[0];
#pragma warning(pop)
};
#pragma pack(pop)

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

extern "C"
void*
__cdecl 
calloc(
	__in size_t n, 
	__in size_t size
	);


extern "C"
int
__cdecl 
vsnprintf(
	__in_ecount(count) char *buf,
	__in size_t count,
	__in const char *fmt,
	__in va_list args
	);

extern "C"
int
__cdecl 
printf(
	__in const char* fmt,
	...
	);
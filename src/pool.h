#pragma once

#include <ntifs.h>
#include <sal.h>

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

__drv_maxIRQL(DISPATCH_LEVEL)
void* 
__cdecl 
PoolAlloc(
	__in size_t size
	);

__drv_maxIRQL(DISPATCH_LEVEL)
void 
__cdecl 
PoolFree(
	__inout void* ptr
	);

__drv_maxIRQL(DISPATCH_LEVEL)
void* 
__cdecl 
PoolReAlloc(
	__in_opt void* ptr, 
	__in size_t size
	);

extern "C"
__drv_maxIRQL(DISPATCH_LEVEL)
void*
__cdecl 
calloc(
	__in size_t n, 
	__in size_t size
	);

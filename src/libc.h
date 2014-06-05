#pragma once

#ifndef _LIBC_POOL_TAG
#define _LIBC_POOL_TAG	'colM'
#endif

// very nice for debug forensics!
struct MEMBLOCK
{
	size_t	size;
#pragma warning(push)               
#pragma warning (disable : 4200)
	char data[0]; 
#pragma warning(pop)
};

#ifdef R32R0
#include "heap.hpp"
decltype(&ExAllocatePoolWithTag) xalloc = UserMalloc;
decltype(&ExFreePoolWithTag) xfree = UserFree;
#else
#include <ntifs.h>
decltype(&ExAllocatePoolWithTag) xalloc = ExAllocatePoolWithTag;
decltype(&ExFreePoolWithTag) xfree = ExFreePoolWithTag;
#endif

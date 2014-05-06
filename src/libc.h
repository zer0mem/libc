#pragma once

#include <ntifs.h>

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

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

int
__cdecl
_vsprintf_s(
	__in_ecount(size) char *buf,
	__in size_t count,
	__in const char *fmt,
	__in va_list args
	);

static UNICODE_STRING g_vsprintf_str = RTL_CONSTANT_STRING(L"vsprintf_s");
decltype(&_vsprintf_s) g_vsprintf_s_proc;

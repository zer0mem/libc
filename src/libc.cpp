#include "libc.h"
#include <stdio.h>

extern "C"
{
	decltype(&malloc) _cc_alloc = nullptr;
	decltype(&free) _cc_free = nullptr;
	decltype(&realloc) _cc_realloc = nullptr;
	decltype(&vsnprintf) _cc_vsnprintf = nullptr;
};

void
set_imports(
	__in decltype(&malloc) cc_alloc,
	__in decltype(&free) cc_free,
	__in decltype(&realloc) cc_realloc,
	__in decltype(&vsnprintf) cc_vsnprintf
	)
{
	_cc_alloc = cc_alloc;
	_cc_free = cc_free;
	_cc_realloc = cc_realloc;
	_cc_vsnprintf = cc_vsnprintf;
}

void*
__cdecl
operator new(
	__in size_t size
	)
{
	return malloc(size);
}

void
__cdecl
operator delete(
	__inout void* ptr
	)
{
	free(ptr);
}

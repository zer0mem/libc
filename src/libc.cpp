#include "libc.h"

decltype(&malloc) cc_alloc = nullptr;
decltype(&free) cc_free = nullptr;
decltype(&realloc) cc_realloc = nullptr;

extern "C"
{
	decltype(&malloc)& _cc_alloc = cc_alloc;
	decltype(&free)& _cc_free = cc_free;
	decltype(&realloc)& _cc_realloc = cc_realloc;
};

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

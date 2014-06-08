#include "heap.h"

HANDLE gCrtHeap = NULL;

void*
__cdecl
UserMalloc(
	__in size_t size
	)
{
	return HeapAlloc(gCrtHeap, HEAP_ZERO_MEMORY, size);
}

void
__cdecl
UserFree(
	__in void* mem
    )
{
	HeapFree(gCrtHeap, HEAP_ZERO_MEMORY, mem);
}

void*
__cdecl
UserRealloc(
	__in_opt void* mem,
	__in size_t size
	)
{
	return HeapReAlloc(gCrtHeap, HEAP_ZERO_MEMORY, mem, size);
}

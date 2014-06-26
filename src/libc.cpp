#include "libc.h"
#include <ntifs.h>
#include <memory>

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

#pragma warning(push)               
#pragma warning (disable : 4565)
__drv_maxIRQL(DISPATCH_LEVEL)
void* 
__cdecl 
malloc(
	__in size_t size
	)
{
	if ((size_t)(~0) - sizeof(MEMBLOCK) < size)
		return nullptr;

	MEMBLOCK* block = static_cast<MEMBLOCK*>(
		ExAllocatePoolWithTag(
			NonPagedPoolNxCacheAligned, 
			size + sizeof(MEMBLOCK), 
			_LIBC_POOL_TAG));

	if (nullptr == block)
		return nullptr;
	block->size = size;	
	return block->data;
}

__drv_maxIRQL(DISPATCH_LEVEL)
void 
__cdecl 
free(
	__inout void* ptr
	)
{
	if (ptr)
		ExFreePoolWithTag(CONTAINING_RECORD(ptr, MEMBLOCK, data), _LIBC_POOL_TAG);
}

__drv_maxIRQL(DISPATCH_LEVEL)
void* 
__cdecl 
realloc(
	__in_opt void* ptr, 
	__in size_t size
	)
{
	if (!ptr)
		return malloc(size);

	if (CONTAINING_RECORD(ptr, MEMBLOCK, data)->size >= size)
		return ptr;

	auto inblock = std::unique_ptr<unsigned char>(static_cast<unsigned char*>(ptr));

	// alloc new block
	void* mem = malloc(size);
	if (!mem)
		return nullptr;

	// copy from old one, not overflow ..
	memcpy(mem, inblock.get(), size);
	return mem;
}

extern "C"
__drv_maxIRQL(DISPATCH_LEVEL)
void*
__cdecl 
calloc(
	__in size_t n, 
	__in size_t size
	)
{
	if (!size)
		return nullptr;
	if ((size_t)(~0) / n < size)
		return nullptr;
	size_t total = n * size;

	void* p = malloc(total);

	if (!p) 
		return nullptr;

	return memset(p, 0, total);
}
#pragma warning(pop)

extern "C"
int
__cdecl 
vsnprintf(
	__in_ecount(count) char *buf,
	__in size_t count,
	__in const char *fmt,
	__in va_list args
	)
{
	return vsprintf_s(buf, count, fmt, args);
}

extern "C"
int
__cdecl 
printf(
	__in const char* fmt,
	...
	)
{
	char buff[0x100] = { 0 };
	va_list arg_list;

	va_start(arg_list, fmt);
	int ret = vsprintf_s(buff, sizeof(buff), fmt, arg_list);
	va_end(arg_list);
	if (ret)
		DbgPrint(buff);
	return ret;
}

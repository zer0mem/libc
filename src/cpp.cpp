#pragma once

#include "cpp.h"

EXTERN_C
int
__cdecl atexit(
	__in void(__cdecl *destructor)(void)
	)
{
	if (!destructor)
		return 0;

	ATEXIT_ENTRY* entry = new ATEXIT_ENTRY(destructor, g_pTopAtexitEntry);
	if (!entry)
		return 0;
	g_pTopAtexitEntry = entry;
	return 1;
}

#if defined(_IA64_) || defined(_AMD64_)
#pragma section(".CRT$XCA",long,read)
__declspec(allocate(".CRT$XCA")) void(*__ctors_begin__[1])(void) = { 0 };
#pragma section(".CRT$XCZ",long,read)
__declspec(allocate(".CRT$XCZ")) void(*__ctors_end__[1])(void) = { 0 };
#pragma data_seg()
#else
#pragma data_seg(".CRT$XCA")
void(*__ctors_begin__[1])(void) = { 0 };
#pragma data_seg(".CRT$XCZ")
void(*__ctors_end__[1])(void) = { 0 };
#pragma data_seg()
#endif

#pragma data_seg(".STL$A")
void(*___StlStartInitCalls__[1])(void) = { 0 };
#pragma data_seg(".STL$L")
void(*___StlEndInitCalls__[1])(void) = { 0 };
#pragma data_seg(".STL$M")
void(*___StlStartTerminateCalls__[1])(void) = { 0 };
#pragma data_seg(".STL$Z")
void(*___StlEndTerminateCalls__[1])(void) = { 0 };
#pragma data_seg()

EXTERN_C
void
__cdecl doexit(
	__in int /*code*/,
	__in int /*quick*/,
	__in int /*retcaller*/
	)
{
	for (ATEXIT_ENTRY* entry = g_pTopAtexitEntry; entry;)
	{
		ATEXIT_ENTRY* next = entry->Next;
		delete entry;
		entry = next;
	}
}

EXTERN_C
int
__cdecl _cinit(
	__in int
	)
{
	for (void(**ctor)(void) = __ctors_begin__ + 1;
		ctor < __ctors_end__;
		ctor++)
	{
		(*ctor)();
	}
	return 0;
}

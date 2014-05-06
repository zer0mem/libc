#pragma once

#include <ntifs.h>

struct ATEXIT_ENTRY
{
	ATEXIT_ENTRY(
		__in void(__cdecl *destructor)(void),
		__in ATEXIT_ENTRY* next
		)
	{
		Destructor = destructor;
		Next = next;
	}

	~ATEXIT_ENTRY()
	{
		Destructor();
	}

	void(_cdecl *Destructor)();
	ATEXIT_ENTRY* Next;
};

static ATEXIT_ENTRY* g_pTopAtexitEntry = nullptr;

EXTERN_C
int
__cdecl _cinit(
	__in int
	);

EXTERN_C
void
__cdecl doexit(
	__in int /*code*/,
	__in int /*quick*/,
	__in int /*retcaller*/
	);

#pragma once

#include <sal.h>

typedef void(__cdecl *Destructor_t)(
	void
	);

struct ATEXIT_ENTRY
{
	ATEXIT_ENTRY(
		__in Destructor_t destructor,
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

	Destructor_t Destructor;
	ATEXIT_ENTRY* Next;
};

static ATEXIT_ENTRY* g_pTopAtexitEntry = nullptr;

extern "C"
int
__cdecl 
cc_atexit(
	__in void(__cdecl *destructor)(void)
	);

extern "C"
int
__cdecl 
cc_init(
	__in int
	);

extern "C"
void
__cdecl 
cc_doexit(
	__in int,
	__in int,
	__in int
	);

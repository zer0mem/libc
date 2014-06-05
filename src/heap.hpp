#pragma once

#include <ntifs.h>

typedef enum _HEAP_INFORMATION_CLASS {

	HeapCompatibilityInformation = 0,
	HeapEnableTerminationOnCorruption = 1


#if ((NTDDI_VERSION > NTDDI_WINBLUE) || \
	(NTDDI_VERSION == NTDDI_WINBLUE && defined(WINBLUE_KBSPRING14)))
	,

	HeapOptimizeResources = 3

#endif


} HEAP_INFORMATION_CLASS;

typedef struct _RTL_CRITICAL_SECTION_DEBUG {
	unsigned short   Type;
	unsigned short    CreatorBackTraceIndex;
	struct _RTL_CRITICAL_SECTION *CriticalSection;
	LIST_ENTRY ProcessLocksList;
	unsigned long EntryCount;
	unsigned long ContentionCount;
	unsigned long Flags;
	unsigned short   CreatorBackTraceIndexHigh;
	unsigned short   SpareWORD;
} RTL_CRITICAL_SECTION_DEBUG, *PRTL_CRITICAL_SECTION_DEBUG, RTL_RESOURCE_DEBUG, *PRTL_RESOURCE_DEBUG;

typedef struct _RTL_CRITICAL_SECTION {
	void* DebugInfo;

	//
	//  The following three fields control entering and exiting the critical
	//  section for the resource
	//

	long LockCount;
	long RecursionCount;
	void* OwningThread;        // from the thread's ClientId->UniqueThread
	void* LockSemaphore;
	size_t SpinCount;        // force size on 64-bit systems when packed
} RTL_CRITICAL_SECTION, *PRTL_CRITICAL_SECTION;

#include <HeapApi.h>

void*
NTAPI
UserMalloc(
	__in POOL_TYPE a,
	__in SIZE_T size,
	__in ULONG b
	)
{
	return HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, size);
}

void
UserFree(
	__in void* mem,
	__in ULONG a
    )
{
	HeapFree(GetProcessHeap(), HEAP_ZERO_MEMORY, mem);
}

#include <sal.h>
#include <intrin.h>
#include <minwindef.h>

extern "C"
EXCEPTION_DISPOSITION 
ExCxxFrameHandler3(
	__in void* pExcept, // Information for this exception
	__in ULONG_PTR RN, // Dynamic information for this frame
	__in void* pContext, // Context info
	__in void* pDC // More dynamic info for this frame
	)
{
	__debugbreak();
	return EXCEPTION_DISPOSITION::ExceptionNestedException;
}

#ifdef _WIN64

extern "C"
void 
_CxxThrowException(
	__in void *, 
	__in _ThrowInfo *
	)
{
}

#else

extern "C"
void
__stdcall
_CxxThrowException(
	__in void *, 
	__in _ThrowInfo *
	)
{
}

#endif

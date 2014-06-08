/*
	- very dangerous "implementation"
	- for real use, necessary proper handling!
*/
#include <ntifs.h>

namespace std
{
	void
	__cdecl 
	_Xbad_alloc() 
	{ 
		DbgBreakPoint(); 
	}

	void 
	__cdecl 
	_Xlength_error(
		__in char const*
		) 
	{ 
		DbgBreakPoint();
	}

	void 
	__cdecl 
	_Xout_of_range(
		__in char const*
		) 
	{ 
		DbgBreakPoint(); 
	}

	char const* 
	__cdecl 
	_Syserror_map(
		__in int
		) 
	{ 
		DbgBreakPoint(); 
		return nullptr; 
	}

	char const* 
	__cdecl 
	_Winerror_map(
		__in int
		) 
	{ 
		DbgBreakPoint(); 
		return nullptr; 
	}
};

extern "C"
EXCEPTION_DISPOSITION 
ExCxxFrameHandler3(
	__in void* pExcept, // Information for this exception
	__in ULONG_PTR RN, // Dynamic information for this frame
	__in void* pContext, // Context info
	__in void* pDC // More dynamic info for this frame
	)
{
	DbgBreakPoint();
	return EXCEPTION_DISPOSITION::ExceptionNestedException;
}

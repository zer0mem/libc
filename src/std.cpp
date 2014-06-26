/*
	- very dangerous "implementation"
	- for real use, necessary proper handling!
*/
#include <sal.h>
#include <intrin.h>
#include <minwindef.h>

namespace std
{
	void
	__cdecl 
	_Xbad_alloc() 
	{ 
		__debugbreak(); 
	}

	void 
	__cdecl 
	_Xlength_error(
		__in char const*
		) 
	{ 
		__debugbreak();
	}

	void 
	__cdecl 
	_Xout_of_range(
		__in char const*
		) 
	{ 
		__debugbreak();
	}

	char const* 
	__cdecl 
	_Syserror_map(
		__in int
		) 
	{ 
		__debugbreak();
		return nullptr; 
	}

	char const* 
	__cdecl 
	_Winerror_map(
		__in int
		) 
	{ 
		__debugbreak();
		return nullptr; 
	}
};

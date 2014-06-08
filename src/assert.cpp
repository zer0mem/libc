#include <ntifs.h>

void 
__cdecl _wassert(
	__in_z const wchar_t * message, 
	__in_z const wchar_t *file,
	__in unsigned line
	) 
{
	return; 
}

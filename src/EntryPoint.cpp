#pragma once

#include "cpp.h"

#ifdef CPP_DRIVER_COMMON

#include <Common/kernel/CppDriver.h>

CCppDriver CCppDriver::m_instance;
DRIVER_OBJECT* CCppDriver::g_pDriverObject = nullptr;

#define STATIC_DRIVER_OBJECT CCppDriver::GetInstance().DriverObject()
#define CPP_MAIN CCppDriver::GetInstance().Main
#define EPILOGUE ;

#else

EXTERN_C
__checkReturn
NTSTATUS
driver_entry(
	__in DRIVER_OBJECT* driverObject,
	__in UNICODE_STRING* registryPath
	);

EXTERN_C
void
unload(
	__in const DRIVER_OBJECT* driverObject
	);

const DRIVER_OBJECT* g_pDriverObject = nullptr;

#define STATIC_DRIVER_OBJECT g_pDriverObject
#define CPP_MAIN driver_entry
#define EPILOGUE unload(STATIC_DRIVER_OBJECT);

#endif

//---------------------------
//-----   UNINSTALL   -------
//---------------------------
void
OnUnload(
__in DRIVER_OBJECT* driverObject
)
{
	UNREFERENCED_PARAMETER(driverObject);
	EPILOGUE
	doexit(0, 0, 0);//call dtors
} // end OnUnload

//---------------------------
//------   INSTALL   --------
//---------------------------
EXTERN_C
NTSTATUS
DriverEntry(
	__in DRIVER_OBJECT* driverObject,
	__in UNICODE_STRING* registryPath
	)
{
	driverObject->DriverUnload = OnUnload;
	STATIC_DRIVER_OBJECT = driverObject;

	_cinit(0);//call ctors

	return CPP_MAIN(driverObject, registryPath);
}

// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include <comdef.h>
#include "AudioEndPointLibrary.h"

_COM_SMARTPTR_TYPEDEF(IMMDeviceEnumerator, __uuidof(IMMDeviceEnumerator));


#define ReturnIfFailed(hr) if (FAILED(hr)) return hr;
static IMMDeviceEnumeratorPtr pDeviceEnumerator;

HRESULT RegisterMMNotificationClient(IMMNotificationClient* notif)
{
    ReturnIfFailed(pDeviceEnumerator.CreateInstance(__uuidof(MMDeviceEnumerator)));
    return pDeviceEnumerator->RegisterEndpointNotificationCallback(notif);
}

HRESULT UnregisterMMNotificationClient(IMMNotificationClient* notif)
{
    return pDeviceEnumerator->UnregisterEndpointNotificationCallback(notif);
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
#ifdef APPVEYOR
    return TRUE;
#else
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
        return SUCCEEDED(RegisterMMNotificationClient(AudioEndPoint::CAudioEndPointLibrary::GetInstance().GetNotifClient()));
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
        break;
	case DLL_PROCESS_DETACH:
        return SUCCEEDED(UnregisterMMNotificationClient(AudioEndPoint::CAudioEndPointLibrary::GetInstance().GetNotifClient()));
	}
	return TRUE;
#endif
}


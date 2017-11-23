// AudioEndPointLibrary.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "AudioDefaultSwitcherLibrary.h"

namespace AudioEndPoint {

   
    CSwitcher& CSwitcher::GetInstance()
    {
        static CSwitcher instance;
        return instance;
    }

	bool CSwitcher::SwitchTo(PCWSTR deviceId, const ERole role) const
	{
		return SUCCEEDED(pPolicyConfig->SetDefaultEndpoint(deviceId, role));
	}

	CSwitcher::CSwitcher()
	{
		HRESULT Result = CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED);


		Result = pPolicyConfig.CreateInstance(__uuidof(CPolicyConfigVistaClient));
		if(FAILED(Result))
		{
			throw std::invalid_argument("Can't instanciate the Policy client");
		}

	}

	CSwitcher::~CSwitcher()
	{
		if(pPolicyConfig != nullptr)
		{
			pPolicyConfig->Release();
		}
	}
}

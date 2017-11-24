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

	bool CSwitcher::SwitchTo(PCWSTR deviceId, const DeviceRole role) const
	{
		if(role == DeviceRole::rAll)
		{
			auto result = true;
			result &= SUCCEEDED(pPolicyConfig->SetDefaultEndpoint(deviceId, eCommunications));
			result &= SUCCEEDED(pPolicyConfig->SetDefaultEndpoint(deviceId, eConsole));
			result &= SUCCEEDED(pPolicyConfig->SetDefaultEndpoint(deviceId, eMultimedia));
			return result;
		}

		return SUCCEEDED(pPolicyConfig->SetDefaultEndpoint(deviceId, static_cast<ERole>(role)));
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

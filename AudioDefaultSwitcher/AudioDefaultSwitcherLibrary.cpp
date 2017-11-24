// AudioEndPointLibrary.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "AudioDefaultSwitcherLibrary.h"
#include "Container.h"

namespace audio_default {

   
    CSwitcher& CSwitcher::get_instance()
    {
        static CSwitcher instance;
        return instance;
    }

	bool CSwitcher::switch_to(PCWSTR deviceId, const DeviceRole role) const
	{
		if(role == DeviceRole::rAll)
		{
			auto result = true;
			result &= SUCCEEDED(pContainer.pPolicyConfig->SetDefaultEndpoint(deviceId, eCommunications));
			result &= SUCCEEDED(pContainer.pPolicyConfig->SetDefaultEndpoint(deviceId, eConsole));
			result &= SUCCEEDED(pContainer.pPolicyConfig->SetDefaultEndpoint(deviceId, eMultimedia));
			return result;
		}

		return SUCCEEDED(pContainer.pPolicyConfig->SetDefaultEndpoint(deviceId, static_cast<ERole>(role)));
	}

	CSwitcher::CSwitcher()
	{
		HRESULT Result = CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED);


		Result = pContainer.pPolicyConfig.CreateInstance(__uuidof(CPolicyConfigVistaClient));
		if(FAILED(Result))
		{
			throw std::invalid_argument("Can't instanciate the Policy client");
		}

	}

	CSwitcher::~CSwitcher()
	{
		if(pContainer.pPolicyConfig != nullptr)
		{
			pContainer.pPolicyConfig->Release();
		}
	}
}

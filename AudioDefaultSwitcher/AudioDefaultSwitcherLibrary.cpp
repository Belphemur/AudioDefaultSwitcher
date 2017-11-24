// AudioEndPointLibrary.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "AudioDefaultSwitcherLibrary.h"
#include "COM_Builder.h"

namespace audio_default {

   
    CSwitcher& CSwitcher::get_instance()
    {
        static CSwitcher instance;
        return instance;
    }

	bool CSwitcher::switch_to(__in PCWSTR deviceId, __in const DeviceRole role) const
	{
		auto policy_config = COM_Builder::get_policy_config();

		if(role == DeviceRole::rAll)
		{
			auto result = true;
			result &= SUCCEEDED(policy_config->SetDefaultEndpoint(deviceId, eCommunications));
			result &= SUCCEEDED(policy_config->SetDefaultEndpoint(deviceId, eConsole));
			result &= SUCCEEDED(policy_config->SetDefaultEndpoint(deviceId, eMultimedia));
			return result;
		}

		return SUCCEEDED(policy_config->SetDefaultEndpoint(deviceId, static_cast<ERole>(role)));
	}

	bool CSwitcher::is_default(const PCWSTR deviceId, const DeviceType type, const DeviceRole role) const
	{
		if (role == DeviceRole::rAll)
		{
			auto result = true;
			result &= this->is_default(deviceId, type, rCommunications);
			result &= this->is_default(deviceId, type, rConsole);
			result &= this->is_default(deviceId, type, rMultimedia);

			return result;
		}

		CDevicePtr pDevice;
		COM_Builder::get_enumerator()->GetDefaultAudioEndpoint(static_cast<EDataFlow>(type), static_cast<ERole>(role), &pDevice);

		LPWSTR defaultId;

		pDevice->GetId(&defaultId);

		return wcscmp(defaultId, deviceId) == 0;
	}

	CSwitcher::CSwitcher()
	{
	
	}

	CSwitcher::~CSwitcher()
	{
	
	}
}

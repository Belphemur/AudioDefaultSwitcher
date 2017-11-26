// Audio.EndPoint.Controller.Wrapper.h

#pragma once
#include "DeviceDefinitions.h"

using namespace System;

namespace AudioDefaultSwitcherWrapper {


	public ref class AudioController
	{
	public:
		static bool SwitchTo(String^ deviceId, DeviceRole role);
		static bool IsDefault(String^ deviceId, DeviceType type, DeviceRole role);

    internal:
       
    private:
        AudioController() {};

	};
}

// Audio.EndPoint.Controller.Wrapper.h

#pragma once

using namespace System;
using namespace audio_default;

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

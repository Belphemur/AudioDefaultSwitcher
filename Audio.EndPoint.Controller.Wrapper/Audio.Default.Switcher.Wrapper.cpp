// This is the main DLL file.

#include "stdafx.h"
#include "Audio.Default.Switcher.Wrapper.h"

using namespace System;
using namespace System::Runtime::InteropServices;

namespace AudioDefaultSwitcherWrapper {
	bool AudioController::SwitchTo(String ^ deviceId, DeviceRole role)
	{
		IntPtr ip = Marshal::StringToHGlobalAnsi(deviceId);
		const wchar_t* str = static_cast<const wchar_t*>(ip.ToPointer());
		return audio_default::CSwitcher::get_instance().switch_to(str, static_cast<audio_default::DeviceRole>(role));
	}

	bool AudioController::IsDefault(String ^ deviceId, DeviceType type, DeviceRole role)
	{
		IntPtr ip = Marshal::StringToHGlobalAnsi(deviceId);
		const wchar_t* str = static_cast<const wchar_t*>(ip.ToPointer());

		return audio_default::CSwitcher::get_instance().is_default(str, static_cast<audio_default::DeviceType>(type), static_cast<audio_default::DeviceRole>(role));
	}
}
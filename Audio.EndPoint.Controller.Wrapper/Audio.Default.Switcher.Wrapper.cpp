// This is the main DLL file.

#include "stdafx.h"
#include "Audio.Default.Switcher.Wrapper.h"

using namespace System;
using namespace audio_default;
using namespace System::Runtime::InteropServices;

namespace AudioDefaultSwitcherWrapper {
	bool AudioController::SwitchTo(String ^ deviceId, DeviceRole role)
	{
		IntPtr ip = Marshal::StringToHGlobalAnsi(deviceId);
		const wchar_t* str = static_cast<const wchar_t*>(ip.ToPointer());
		return CSwitcher::get_instance().switch_to(str, role);
	}

	bool AudioController::IsDefault(String ^ deviceId, DeviceType type, DeviceRole role)
	{
		IntPtr ip = Marshal::StringToHGlobalAnsi(deviceId);
		const wchar_t* str = static_cast<const wchar_t*>(ip.ToPointer());

		return CSwitcher::get_instance().is_default(str, type, role);
	}
}
// This is the main DLL file.

#include "stdafx.h"
#include "Audio.Default.Switcher.Wrapper.h"

using namespace System;

namespace AudioDefaultSwitcherWrapper {
	bool AudioController::SwitchTo(String ^ deviceId, DeviceRole role)
	{
		pin_ptr<const wchar_t> convertedValue = PtrToStringChars(deviceId);
		const wchar_t *constValue = convertedValue;
		return audio_default::CSwitcher::get_instance().switch_to(constValue, static_cast<audio_default::DeviceRole>(role));
	}

	bool AudioController::IsDefault(String ^ deviceId, DeviceType type, DeviceRole role)
	{
		pin_ptr<const wchar_t> convertedValue = PtrToStringChars(deviceId);
		const wchar_t *constValue = convertedValue;

		return audio_default::CSwitcher::get_instance().is_default(constValue, static_cast<audio_default::DeviceType>(type), static_cast<audio_default::DeviceRole>(role));
	}
}
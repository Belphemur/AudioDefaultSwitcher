#pragma once

#include "DeviceType.h"
#include "DeviceRole.h"

namespace AudioDefaultSwitcherWrapper {

	public enum class DeviceType
	{
		Playback = audio_default::tPlayback,
		Recording = audio_default::tRecording,
		All = audio_default::tAll
	};

	public enum class DeviceRole
	{
		Console = audio_default::rConsole,
		Communication = audio_default::rCommunications,
		Multimedia = audio_default::rMultimedia,
		All = audio_default::rAll
	};

}

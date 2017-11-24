#pragma once
#include "ComDefinitions.h"

namespace audio_default {
	struct	COM_Builder
	{
	public:

		static CDeviceEnumeratorPtr get_enumerator()
		{
			CDeviceEnumeratorPtr CEnumerator;

			auto result = CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED);

			result = CEnumerator.CreateInstance(__uuidof(MMDeviceEnumerator));

			if (FAILED(result))
				throw std::invalid_argument("Can't Instanciate device enumerator");

			return CEnumerator;
		}

		static CPolicyConfigPtr get_policy_config()
		{
			CPolicyConfigPtr CPolicyConfig;

			auto result = CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED);

			result = CPolicyConfig.CreateInstance(__uuidof(CPolicyConfigVistaClient));

			if (FAILED(result))
				throw std::invalid_argument("Can't Instanciate Policy config");

			return CPolicyConfig;
		}


	};
}

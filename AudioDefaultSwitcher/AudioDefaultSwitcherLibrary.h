#pragma once

#include "DeviceRole.h"
#include "Container.h"

// This class is exported from the AudioEndPointLibrary.dll
namespace audio_default {


    class AUDIODEFAULTSWITCHER_API CSwitcher {
    public:    
		static CSwitcher& get_instance();
	    bool switch_to(__in PCWSTR deviceId, __in const DeviceRole role) const;
    

    private:
        CSwitcher(void);
		~CSwitcher();
        CSwitcher(CSwitcher const&) = delete;
		void operator=(CSwitcher const&) = delete;

		Container pContainer;
    };


}

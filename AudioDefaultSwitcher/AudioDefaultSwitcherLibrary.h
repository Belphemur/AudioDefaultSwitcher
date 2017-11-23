#include "ComDefinitions.h"
// This class is exported from the AudioEndPointLibrary.dll
namespace AudioEndPoint {


    class AUDIODEFAULTSWITCHER_API CSwitcher {
    public:    
		static CSwitcher& GetInstance();
	    bool SwitchTo(PCWSTR deviceId, const ERole role) const;
    

    private:
        CSwitcher(void);
		~CSwitcher();
        CSwitcher(CSwitcher const&) = delete;
		void operator=(CSwitcher const&) = delete;

		CPolicyConfigPtr pPolicyConfig;
    };


}

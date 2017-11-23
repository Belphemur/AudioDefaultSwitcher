
#include "AudioEndPointLibraryImpl.h"


// This class is exported from the AudioEndPointLibrary.dll
namespace AudioEndPoint {


    class AUDIOENDPOINTLIBRARY_API CAudioEndPointLibrary {
    public:    
        static CAudioEndPointLibrary& GetInstance();
    

    private:
        CAudioEndPointLibrary(void);
        CAudioEndPointLibrary(CAudioEndPointLibrary const&) = delete;
		void operator=(CAudioEndPointLibrary const&) = delete;
    };


}

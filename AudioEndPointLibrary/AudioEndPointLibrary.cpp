// AudioEndPointLibrary.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "AudioEndPointLibrary.h"

namespace AudioEndPoint {

   
    CAudioEndPointLibrary& CAudioEndPointLibrary::GetInstance()
    {
        static CAudioEndPointLibrary instance;
        return instance;
    }

}

#pragma once
#include "PolicyConfig.h"

typedef _com_ptr_t< _com_IIID<IMMDeviceEnumerator, &__uuidof(IMMDeviceEnumerator)> > CDeviceEnumeratorPtr;
typedef _com_ptr_t< _com_IIID<IPolicyConfigVista, &__uuidof(IPolicyConfigVista)> > CPolicyConfigPtr;
typedef _com_ptr_t< _com_IIID<IMMDevice, &__uuidof(IMMDevice)> > CDevicePtr;

#define ReturnIfFailed(hr) if (FAILED(hr)) return hr;
#define SAFE_RELEASE(punk)  \
              if ((punk) != nullptr)  \
                { (punk)->Release(); (punk) = NULL; }

#define SAFE_DELETE(punk)  \
              if ((punk) != NULL)  \
                { delete (punk); (punk) = NULL; }
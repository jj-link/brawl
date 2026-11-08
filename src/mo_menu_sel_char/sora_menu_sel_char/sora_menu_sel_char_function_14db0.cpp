#include <mu/mu_object.h>
#pragma force_active on
extern "C" void fn_10_14DB0(void* arg0, int arg1) {
    MuObject* obj = *(MuObject**)((char*)arg0 + 0xd4);
    obj->setFrameTex((float)arg1);
    obj->setFrameNode((float)arg1);
    obj->setFrameMatCol((float)arg1);
}

#pragma force_active on

#include <mu/mu_object.h>

extern "C" {
extern const float lbl_14_rodata_4C4;
}

extern "C" void fn_14_7E54(void* self) {
    MuObject* obj = *(MuObject**)((unsigned int)self + 0xB4);
    obj->setFrameVisible(lbl_14_rodata_4C4);
    obj->setFrameNode((float)*(int*)((unsigned int)self + 0x25F4));
}

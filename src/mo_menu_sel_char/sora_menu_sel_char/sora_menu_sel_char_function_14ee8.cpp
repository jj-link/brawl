#include <types.h>
#include <lib/BrawlHeaders/Brawl/Include/mu/mu_object.h>
#pragma force_active on

extern const float lbl_10_rodata_6B8;

extern "C" {
void setFrameTex__8MuObjectFf(MuObject* self, float frame);

void fn_10_14EE8(void* arg0, int frame) {
    setFrameTex__8MuObjectFf(*(MuObject**)((char*)arg0 + 0xD8),
        lbl_10_rodata_6B8 + (float)frame);
}
}

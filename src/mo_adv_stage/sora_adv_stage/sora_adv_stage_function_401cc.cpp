#include <types.h>
#include <mu/mu_object.h>
#include <nw4r/g3d/g3d_scnmdl.h>
#include <stdio.h>
#pragma force_active on
extern "C" { extern const char lbl_40_data_17C50[];
void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*, void*, char*); }
extern "C" void fn_40_401CC(u8* self, s32 a1, s32 a2, s32 a3) {
    char buf[8];
    s32 base = 0x60;
    if (a1 == 0) base = 0x38;
    MuObject* obj = *(MuObject**)(self + 0x710 + (base + a3 - 1) * 4);
    obj->setFrameTex((f32)a3);
    s32 n = *(s32*)(self + 0xc1c);
    void* mdl = *(void**)(self + 0x934 + (n + 2) * 4);
    sprintf(buf, lbl_40_data_17C50, a2);
    Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(mdl, obj->m_sceneModel, buf);
}

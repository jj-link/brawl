#include <mu/mu_msg.h>
#include <stdio.h>
#pragma force_active on
extern "C" {
void fn_31_23D0(void*, s32);
void fn_31_2558(void*);
extern void* g_GameGlobal;
extern char lbl_31_data_240[];
extern float lbl_31_rodata_40;
}
extern "C" void fn_31_2264(u8* self, s32 idx) {
    char buf8[10] = {0};
    char buf14[10] = {0};
    u8* r27;
    MuObject* r26;
    r27 = *(u8**)((u8*)g_GameGlobal + 0x30);
    fn_31_23D0(self, idx);
    fn_31_2558(self);
    (*(MuMsg**)(self + 0x1C0))->printIndex(1, idx, 0);
    (*(MuObject**)(self + 0x1CC))->setFrameTex(lbl_31_rodata_40 + (float)idx);
    r26 = *(MuObject**)(self + 0x1D0);
    r26->setFrameTex((float)(*(s32*)(r27 + 8 + idx * 20) + 1));
    r26->setFrameMatCol((float)(*(s32*)(r27 + 8 + idx * 20) + 1));
    sprintf(buf8, lbl_31_data_240, *(s32*)(r27 + 0x60C));
    (*(MuMsg**)(self + 0x1C0))->printf(2, buf8);
    sprintf(buf14, lbl_31_data_240, (s32)*(float*)(r27 + 0x2A8));
    (*(MuMsg**)(self + 0x1C0))->printf(6, buf14);
}
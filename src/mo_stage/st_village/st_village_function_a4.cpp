#pragma force_active on
#include <types.h>

extern "C" {
void __ct__7stMeleeFPCcQ26Stages11srStageKind(void*, const char*, int);
void* memset(void*, int, unsigned long);
extern char lbl_70_data_0[];
extern char lbl_70_data_6E0[];
extern const float lbl_70_rodata_0;
}

extern "C" void* fn_70_A4(char* arg0) {
    __ct__7stMeleeFPCcQ26Stages11srStageKind(arg0, lbl_70_data_0, 0x21);
    *(char**)(arg0 + 0x3C) = lbl_70_data_6E0;
    *(s32*)(arg0 + 0x288) = 0;
    *(s8*)(arg0 + 0x1D8) = 5;
    *(s8*)(arg0 + 0x1D9) = 6;
    memset(arg0 + 0x1E0, 0, 0x84);
    *(s8*)(arg0 + 0x265) = 0;
    *(s8*)(arg0 + 0x26C) = 6;
    *(f32*)(arg0 + 0x268) = lbl_70_rodata_0;
    *(s8*)(arg0 + 0x26D) = 0;
    *(f32*)(arg0 + 0x270) = lbl_70_rodata_0;
    *(s8*)(arg0 + 0x274) = 6;
    *(s8*)(arg0 + 0x275) = 0;
    *(f32*)(arg0 + 0x278) = lbl_70_rodata_0;
    *(s8*)(arg0 + 0x27C) = 6;
    *(s8*)(arg0 + 0x27D) = 6;
    *(s8*)(arg0 + 0x27E) = 6;
    *(s8*)(arg0 + 0x27F) = 6;
    *(s8*)(arg0 + 0x280) = 6;
    *(s8*)(arg0 + 0x281) = 6;
    *(s8*)(arg0 + 0x282) = 6;
    *(s8*)(arg0 + 0x283) = 6;
    *(s8*)(arg0 + 0x284) = 6;
    *(s8*)(arg0 + 0x285) = 6;
    *(s8*)(arg0 + 0x286) = 6;
    *(s8*)(arg0 + 0x287) = 6;
    *(s32*)(arg0 + 0x28C) = 0;
    *(s32*)(arg0 + 0x290) = 0;
    return arg0;
}

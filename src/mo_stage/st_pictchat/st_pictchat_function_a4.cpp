#pragma force_active on
#include <types.h>

extern "C" {
void __ct__7stMeleeFPCcQ26Stages11srStageKind(void*, const char*, int);
void* memset(void*, int, unsigned long);
extern char lbl_73_data_0[];
extern char lbl_73_data_888[];
extern const float lbl_73_rodata_0;
}

extern "C" void* fn_73_A4(char* arg0) {
    __ct__7stMeleeFPCcQ26Stages11srStageKind(arg0, lbl_73_data_0, 0x24);
    *(char**)(arg0 + 0x3C) = lbl_73_data_888;
    *(s8*)(arg0 + 0x1D8) = 0;
    *(f32*)(arg0 + 0x1DC) = lbl_73_rodata_0;
    *(s8*)(arg0 + 0x1E0) = 1;
    *(s8*)(arg0 + 0x1E1) = 0;
    *(s8*)(arg0 + 0x1E2) = 0;
    *(s8*)(arg0 + 0x1E3) = 0;
    *(s8*)(arg0 + 0x1E4) = 0;
    memset(arg0 + 0x1E5, 0, 0x1B);
    *(u8*)(arg0 + 0x200) = 0xFF;
    *(s8*)(arg0 + 0x201) = 5;
    *(s8*)(arg0 + 0x202) = 5;
    *(s8*)(arg0 + 0x203) = 5;
    *(s8*)(arg0 + 0x204) = 5;
    *(s8*)(arg0 + 0x205) = 5;
    *(s8*)(arg0 + 0x206) = 5;
    memset(arg0 + 0x208, 0, 0x6C);
    memset(arg0 + 0x274, 0, 0x15C);
    *(s32*)(arg0 + 0x3D0) = 0;
    memset(arg0 + 0x3D4, 0, 0x18);
    *(s8*)(arg0 + 0x3EC) = 0;
    *(s32*)(arg0 + 0x3F0) = 0;
    memset(arg0 + 0x3F4, 0, 0x18);
    *(s8*)(arg0 + 0x40C) = 5;
    *(s8*)(arg0 + 0x40D) = 5;
    *(s8*)(arg0 + 0x40E) = 0;
    memset(arg0 + 0x410, 0, 0x18);
    *(s32*)(arg0 + 0x428) = 0;
    *(s32*)(arg0 + 0x42C) = 0;
    *(s32*)(arg0 + 0x430) = -1;
    return arg0;
}

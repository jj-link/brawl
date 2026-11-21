#include <types.h>
#include <cstring>
#include <gr/gr_gimmick_motion_path.h>
#pragma force_active on

extern "C" void __ct__9grGimmickFPCc(void*, const char*);
extern "C" char lbl_27_data_56D80[];
extern "C" const float lbl_27_rodata_43A8[];
extern "C" float lbl_27_data_547E0;

extern "C" void* __ct__19grGimmickMotionPathFPCcPCc(void* self, const char* name, const char* nodeName) {
    __ct__9grGimmickFPCc(self, name);
    u8* p = (u8*)self;
    *(void**)(p + 0x3c) = lbl_27_data_56D80;
    *(u8*)(p + 0x14c) = 0;
    *(float*)(p + 0x150) = 0.0f;
    *(float*)(p + 0x154) = 0.0f;
    *(int*)(p + 0x160) = 0;
    *(float*)(p + 0x168) = 1.0f;
    *(float*)(p + 0x16c) = 1.0f;
    *(float*)(p + 0x170) = 1.0f;
    *(float*)(p + 0x174) = 0.1f;
    *(int*)(p + 0x178) = 0;
    *(int*)(p + 0x17c) = 0;
    memset(p + 0x180, 0, 0x20);
    strncpy((char*)p + 0x180, nodeName, 0x1f);
    float factor = 0.0f;
    float speed = lbl_27_data_547E0;
    factor = factor * speed;
    *(int*)(p + 0xe4) = 0;
    float value = *(float*)(p + 0x64) * factor;
    *(float*)(p + 0x158) = value;
    *(float*)(p + 0x15c) = value;
    return self;
}
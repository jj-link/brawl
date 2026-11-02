#pragma force_active on
#include <string.h>

struct FlagByte {
    unsigned char top : 1;
    unsigned char rest : 7;
};

extern "C" {
extern const char lbl_71_data_0[];
extern const char lbl_71_data_3D0[];
extern const float lbl_71_rodata_0;
extern const float lbl_71_rodata_4;

void __ct__7stMeleeFPCcQ26Stages11srStageKind(void*, const char*, int);
void initialize__15stCollisionWorkFv(void*);

void* fn_71_A4(void* self) {
    char* p = (char*)self;
    __ct__7stMeleeFPCcQ26Stages11srStageKind(self, lbl_71_data_0, 0x22);
    *(const char**)(p + 0x3C) = lbl_71_data_3D0;
    memset(p + 0x1E0, 0, 0x9C);
    *(float*)(p + 0x1F8) = lbl_71_rodata_0;
    *(float*)(p + 0x1FC) = lbl_71_rodata_0;
    *(float*)(p + 0x200) = lbl_71_rodata_4;
    *(float*)(p + 0x204) = lbl_71_rodata_0;
    *(float*)(p + 0x208) = lbl_71_rodata_0;
    *(float*)(p + 0x20C) = lbl_71_rodata_4;
    memset(p + 0x27C, 0, 0x18);
    *(unsigned char*)(p + 0x294) = 0;
    *(unsigned char*)(p + 0x295) = 6;
    *(unsigned char*)(p + 0x296) = 9;
    *(unsigned char*)(p + 0x297) = 0;
    *(float*)(p + 0x298) = lbl_71_rodata_0;
    *(float*)(p + 0x29C) = lbl_71_rodata_0;
    *(float*)(p + 0x2A0) = lbl_71_rodata_0;
    *(unsigned char*)(p + 0x2A4) = 9;
    *(unsigned char*)(p + 0x2A5) = 6;
    *(unsigned char*)(p + 0x2A6) = 0;
    *(unsigned char*)(p + 0x2A7) = 0;
    *(float*)(p + 0x2A8) = lbl_71_rodata_0;
    *(float*)(p + 0x2AC) = lbl_71_rodata_0;
    *(unsigned char*)(p + 0x2B0) = 6;
    *(unsigned char*)(p + 0x2B1) = 6;
    *(unsigned char*)(p + 0x2B2) = 6;
    *(unsigned char*)(p + 0x2B3) = 6;
    *(float*)(p + 0x2B4) = lbl_71_rodata_0;
    *(float*)(p + 0x2B8) = lbl_71_rodata_0;
    initialize__15stCollisionWorkFv(p + 0x2BC);
    *(short*)(p + 0x2C8) = 2;
    initialize__15stCollisionWorkFv(p + 0x2CC);
    *(short*)(p + 0x2D8) = 2;
    *(unsigned char*)(p + 0x2DC) = 6;
    *(int*)(p + 0x2E0) = -1;
    *(unsigned char*)(p + 0x2E4) = 6;
    *(int*)(p + 0x1D8) = 0;
    ((FlagByte*)(p + 0x1DC))->top = 0;
    *(unsigned char*)(p + 0x2E5) = 0;
    *(unsigned char*)(p + 0x2E6) = 0;
    return self;
}
}

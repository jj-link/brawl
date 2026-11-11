#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_804883B8[];
extern const float lbl_805A4488;
extern const float lbl_805A448C;
extern const float lbl_805A4490;
extern const float lbl_805A4494;
extern const float lbl_805A4498;
extern const float lbl_805A449C;
extern const float lbl_805A44A0;
extern const float lbl_805A44A4;
extern const float lbl_805A44A8;
extern const float lbl_805A44AC;
extern const float lbl_805A44B0;
extern const float lbl_805A44B4;
extern const float lbl_805A44B8;

void fn_802F00DC(void* arg0) {
    unsigned char* p = (unsigned char*)arg0;
    *(unsigned short*)(p + 0x06) = 1;
    *(void**)(p + 0x00) = &lbl_804883B8[0];
    *(float*)(p + 0x10) = lbl_805A4488;
    *(float*)(p + 0x14) = lbl_805A448C;
    *(float*)(p + 0x18) = lbl_805A4488;
    *(float*)(p + 0x1C) = lbl_805A4488;
    p[0x96] = 1;
    *(unsigned int*)(p + 0x20) = 0x400;
    *(float*)(p + 0x30) = lbl_805A4490;
    *(float*)(p + 0x34) = lbl_805A4490;
    *(float*)(p + 0x38) = lbl_805A4490;
    *(float*)(p + 0x3C) = lbl_805A4488;
    *(float*)(p + 0x40) = lbl_805A4494;
    *(float*)(p + 0x44) = lbl_805A4494;
    *(float*)(p + 0x48) = lbl_805A4494;
    *(float*)(p + 0x4C) = lbl_805A4488;
    *(unsigned int*)(p + 0x54) = 0;
    *(unsigned int*)(p + 0x64) = 0;
    *(float*)(p + 0x6C) = lbl_805A4498;
    *(float*)(p + 0x70) = lbl_805A449C;
    *(float*)(p + 0x24) = lbl_805A44A0;
    *(unsigned int*)(p + 0x74) = 4;
    *(unsigned int*)(p + 0x78) = 1;
    *(float*)(p + 0x50) = lbl_805A44A4;
    p[0x28] = 0;
    *(float*)(p + 0x90) = lbl_805A44A8;
    *(float*)(p + 0x58) = lbl_805A44AC;
    *(float*)(p + 0x5C) = lbl_805A44B0;
    *(float*)(p + 0x7C) = lbl_805A44B4;
    *(unsigned int*)(p + 0x80) = 0x14;
    p[0x94] = 1;
    p[0x8C] = 1;
    *(float*)(p + 0x84) = lbl_805A44A4;
    *(float*)(p + 0x88) = lbl_805A449C;
    p[0x68] = 2;
    p[0x95] = 2;
    *(float*)(p + 0x98) = lbl_805A44B8;
    *(unsigned int*)(p + 0x60) = 0;
}
}
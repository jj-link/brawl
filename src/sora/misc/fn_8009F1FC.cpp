#include <types.h>
#pragma force_active on

extern const float lbl_805A1E30;
extern const float lbl_805A1E6C;
extern const float lbl_805A1E70;
extern const float lbl_805A1E74;
extern const float lbl_805A1E54;

struct Flags {
    unsigned int a : 12;
    unsigned int b : 3;
    unsigned int c : 17;
};

extern "C" void fn_8009F1FC(u8* p) {
    float e;
    float d;
    float c;
    float b;
    float a;
    a = lbl_805A1E30;
    b = lbl_805A1E6C;
    c = lbl_805A1E70;
    d = lbl_805A1E74;
    e = lbl_805A1E54;
    ((Flags*)(p + 8))->b = 0;
    *(u16*)(p + 0xC) = 0;
    *(float*)(p + 0x18) = a;
    *(float*)(p + 0x14) = a;
    *(float*)(p + 0x10) = a;
    *(float*)(p + 0x24) = a;
    *(float*)(p + 0x20) = a;
    *(float*)(p + 0x1C) = a;
    *(float*)(p + 0x28) = a;
    *(float*)(p + 0x2C) = b;
    *(float*)(p + 0x30) = c;
    *(float*)(p + 0x34) = d;
    *(float*)(p + 0x38) = e;
    *(float*)(p + 0x3C) = b;
    *(float*)(p + 0x40) = c;
    *(float*)(p + 0x44) = d;
    *(float*)(p + 0x48) = e;
    *(float*)(p + 0x4C) = b;
    *(float*)(p + 0x50) = c;
    *(float*)(p + 0x54) = d;
    *(float*)(p + 0x58) = e;
    *(float*)(p + 0x5C) = a;
}
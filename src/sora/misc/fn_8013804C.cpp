#include <types.h>
#pragma force_active on

extern "C" {
extern f32 lbl_805A2A80;

void fn_8013804C(void* arg0) {
    f32 f = lbl_805A2A80;
    s16 a = 0;
    u8 b = 7;
    u32 c = 0xFFFF;
    u8* base = (u8*)arg0;
    *(s16*)(base + 0x10) = a;
    *(u8*)(base + 0x12) = b;
    *(f32*)(base + 0x14) = f;
    *(u32*)(base + 0x3C) = c;
    *(u8*)(base + 0x40) = 0;
    *(u8*)(base + 0x41) = 0;
}
}

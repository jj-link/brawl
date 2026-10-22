#include <types.h>
#pragma force_active on
typedef float f32;

extern "C" void fn_8009CF60(void* arg0, void* arg1) {
    u8* a = (u8*)arg0;
    f32* b = (f32*)arg1;
    f32 f8;
    f32 f9;
    f32 f10;
    f32 f11;
    int r0 = 0;
    if (*(f32*)(a + 0x168) != b[0] || *(f32*)(a + 0x16C) != b[1]) {
        r0 = 1;
    }
    if (r0 != 0) {
        f9 = b[0];
        f8 = b[1];
        f11 = *(f32*)(a + 0xA4) + f9;
        f10 = *(f32*)(a + 0xA8) + f8;
        *(f32*)(a + 0x168) = f9;
        *(f32*)(a + 0x16C) = f8;
        *(f32*)(a + 0x148) = *(f32*)(a + 0x128) + f11;
        *(f32*)(a + 0x14C) = *(f32*)(a + 0x12C) + f11;
        *(f32*)(a + 0x150) = *(f32*)(a + 0x130) + f10;
        *(f32*)(a + 0x154) = *(f32*)(a + 0x134) + f10;
        *(f32*)(a + 0x158) = *(f32*)(a + 0x138) + f11;
        *(f32*)(a + 0x15C) = *(f32*)(a + 0x13C) + f11;
        *(f32*)(a + 0x160) = *(f32*)(a + 0x140) + f10;
        *(f32*)(a + 0x164) = *(f32*)(a + 0x144) + f10;
    }
}

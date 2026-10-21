#include <types.h>
#pragma force_active on

extern "C" {
void fn_800A1420(u8* p) {
    f32 f0;
    f32 f1;
    f32 f2;
    f32 f3;
    f32 f4;
    f32 f5;
    u8* src = *(u8**)p;
    f5 = *(f32*)(src + 0x60);
    *(f32*)(p + 0x0C) = f5;
    f4 = *(f32*)(src + 0x64);
    *(f32*)(p + 0x10) = f4;
    f3 = *(f32*)(src + 0x68);
    *(f32*)(p + 0x14) = f3;
    f2 = *(f32*)(src + 0x6C);
    *(f32*)(p + 0x24) = f2;
    f1 = *(f32*)(src + 0x70);
    *(f32*)(p + 0x28) = f1;
    f0 = *(f32*)(src + 0x74);
    *(f32*)(p + 0x2C) = f0;
    *(f32*)(p + 0x48) = f5;
    *(f32*)(p + 0x4C) = f4;
    *(f32*)(p + 0x50) = f3;
    *(f32*)(p + 0x60) = f2;
    *(f32*)(p + 0x64) = f1;
    *(f32*)(p + 0x68) = f0;
}
}

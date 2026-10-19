#include <types.h>
#pragma force_active on

extern "C" s32 fn_119_9D5C();

extern "C" float fn_119_9D04(u8* base, void*, s32 a, s32 b) {
    u8* p = base + fn_119_9D5C() * 0xc0;
    float* f = *(float**)(p + a * 4 - 0x3e70);
    return f[b];
}

#include <types.h>
#pragma force_active on

extern "C" s32 fn_94_B398();

extern "C" float fn_94_B340(u8* base, void* unused, s32 a, s32 b) {
    u8* p = base + fn_94_B398() * 0x9c;
    p = p + a * 4;
    float* f = *(float**)(p - 0x3e70);
    return f[b];
}

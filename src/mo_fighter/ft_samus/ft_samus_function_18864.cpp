#include <types.h>
#pragma force_active on

extern "C" s32 fn_94_B398();

extern "C" s32 fn_94_18864(s32 a, s32 unused, s32 b, s32 c) {
    s32 x = (a + 0xFFFF0000) + fn_94_B398() * 8;
    x = x + b * 4;
    s32* t = *(s32**)(x - 0x7680);
    return t[c];
}

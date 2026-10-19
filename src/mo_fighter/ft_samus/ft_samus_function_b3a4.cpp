#include <types.h>
#pragma force_active on

extern "C" s32 fn_94_B398();

extern "C" s32 fn_94_B3A4(u8* base, void* unused, s32 a, s32 b) {
    u8* p = base - 0x10000 + fn_94_B398() * 0x1c;
    p = p + a * 4;
    s32* t = *(s32**)(p - 0x75b8);
    return t[b];
}

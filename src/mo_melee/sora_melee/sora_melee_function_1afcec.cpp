#include <types.h>
#pragma force_active on

extern "C" void* fn_27_1AFCEC(void* p, s32 idx)
{
    s32* q = (s32*)p;
    s32 s = q[2] >> 22;
    s32 r = s + idx;
    if (r >= 0x12f) {
        r -= 0x12f;
    }
    return (char*)p + 0xc + r * 4;
}

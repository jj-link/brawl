#include <types.h>
#pragma force_active on

extern "C" void* fn_27_1B0BE8(u8* self, s32 idx)
{
    s32 t = *(s32*)(self + 8) >> 29;
    s32 n = t + idx;
    if (n >= 2) {
        n -= 2;
    }
    return self + (n << 4) + 0xC;
}

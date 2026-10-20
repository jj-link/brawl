#include <types.h>
#pragma force_active on

extern "C" void* fn_27_2EB644(void* self, s32 idx)
{
    s32 v = *(s32*)((u8*)self + 0x18) >> 29;
    s32 n = v + idx;
    if (n >= 3) {
        n -= 3;
    }
    return (u8*)self + 0x1c + n * 12;
}

#include <types.h>
#pragma force_active on

extern "C" void* fn_27_295B24(void* self, s32 idx)
{
    s32 k = (((s32*)self)[2] >> 28) + idx;
    if (k >= 5) {
        k -= 5;
    }
    return (char*)self + k * 4 + 0xC;
}

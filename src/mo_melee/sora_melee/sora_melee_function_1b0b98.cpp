#include <types.h>
#pragma force_active on

extern "C" {
void* fn_27_1B0B98(u8* self, s32 idx)
{
    s32 v = *(s32*)(self + 8) >> 26;
    s32 n = v + idx;
    if (n >= 0x19) {
        n -= 0x19;
    }
    return self + (n << 4) + 0xc;
}
}

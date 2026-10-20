#include <types.h>
#pragma force_active on

extern "C" void *fn_27_122C54(void *object, s32 index)
{
    s32 field = *(s32 *)((u8 *)object + 8) >> 26;
    s32 sum = field + index;
    if (sum >= 0x10)
        sum -= 0x10;
    return (u8 *)object + (sum << 3) + 0xC;
}

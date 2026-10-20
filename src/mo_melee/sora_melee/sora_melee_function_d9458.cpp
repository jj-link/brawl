#include <types.h>
#pragma force_active on

extern "C" void *fn_27_D9458(void *p1, s32 p2)
{
    s32 index = (s32)(*(s32 *)((char *)p1 + 8) >> 26) + p2;

    if (index >= 0x1D)
        index -= 0x1D;

    return (char *)p1 + index * 0x30 + 0xC;
}

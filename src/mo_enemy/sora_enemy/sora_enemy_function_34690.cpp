#include <types.h>
#pragma force_active on

extern "C" {
void fn_41_34690(void* dst, const void* src, u32 p3, const s16* p4, s16 p5)
{
    u32* d = (u32*)dst;
    const u32* s = (const u32*)src;
    d[0] = s[0];
    d[1] = s[1];
    d[2] = p3;
    *(s16*)((u8*)dst + 0xC) = *p4;
    *(s16*)((u8*)dst + 0xE) = p5;
}
}

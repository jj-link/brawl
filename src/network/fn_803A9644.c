#pragma force_active on
#include <types.h>

void* fn_803A9644(void* dest, const void* src, u32 size)
{
    u8* d = (u8*)dest;
    const u8* s = (const u8*)src;
    if (((u32)d & 3) == 0 && ((u32)s & 3) == 0) {
        while (size > 3) {
            *(u32*)d = *(const u32*)s;
            d += 4;
            s += 4;
            size -= 4;
        }
    }
    while (size--) {
        *d++ = *s++;
    }
    return dest;
}
#pragma force_active on
#include <types.h>

void* fn_803D6224(void* dst, const void* src, u32 n)
{
    u8* cp = (u8*)dst;
    const u8* fp = (const u8*)src;

    if (((u32)cp & 3) == 0) {
        if (((u32)fp & 3) == 0) {
            while (n > 3) {
                *(u32*)cp = *(const u32*)fp;
                cp += 4;
                fp += 4;
                n -= 4;
            }
        }
    }
    while (n--) {
        *cp++ = *fp++;
    }
    return dst;
}

#include <types.h>
#pragma force_active on

extern "C" {
s32 fn_801AFB44(u8* p) {
    s32 base = *(s32*)(p + 0xfc);
    if (base != 0) {
        u16 n = *(u16*)(p + 0x102);
        u8 m = p[0x101];
        return base + m * ((n * 0x30 + 0x1F) & ~0x1F);
    }
    return 0;
}
}

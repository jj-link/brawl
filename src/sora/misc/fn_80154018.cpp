#include <types.h>
#pragma force_active on

extern "C" s32 fn_80154018(u8* arg) {
    u32 count = *(u32*)(arg + 0xB4);
    s32 total;
    u32 i = 0;
    total = (s32)count * 12 + 8;
    for (i = 0; i < count; i++) {
        total += *(s32*)(arg + i * 0x24 + 0x1C);
        total += 0x20;
    }
    s32 r = total & 0xF;
    if (r != 0) {
        total += 0x10 - r;
    }
    return total;
}

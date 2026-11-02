#include <types.h>
#pragma force_active on

extern "C" s32 fn_801902E8(s32* base, s32 index, s32* out) {
    s32 root = *base;
    u8* entry = (u8*)(root + (index / 2) * 0x30);
    if (entry[0x80] == 0) {
        return 0;
    }
    u32 bits = (u32)entry[0x86] << 24;
    bits |= (u32)entry[0x87] << 16;
    bits |= (u32)entry[0x88] << 8;
    bits |= entry[0x89];
    if (index & 1) {
        *out = (bits >> 14) & 0x1F;
    } else {
        *out = (bits >> 4) & 0x1F;
    }
    return 1;
}

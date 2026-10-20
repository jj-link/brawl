#include <types.h>
#pragma force_active on

extern "C" {
bool fn_27_7B3C4(const u32* flags, s32 bit, u8* out) {
    if (bit <= -1 || bit >= 1) {
        return false;
    }
    u32 mask = 1u << bit;
    if (flags[0] & mask) {
        u32 v = flags[1] & mask;
        *out = ((u32)(-(s32)v) | v) >> 31;
        return true;
    }
    return false;
}
}

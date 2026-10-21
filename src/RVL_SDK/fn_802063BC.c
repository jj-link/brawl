#include <types.h>
#pragma force_active on

extern u16 lbl_8047B2E0[];

s32 fn_802063BC(s32 arg0) {
    s32 offset;
    if (arg0 <= -0x388) {
        return 0;
    }
    if (arg0 >= 0x3C) {
        return 0xFF64;
    }
    offset = arg0 + 0x388;
    return lbl_8047B2E0[offset];
}

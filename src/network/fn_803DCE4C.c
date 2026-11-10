#pragma force_active on
#include <types.h>

extern s32 fn_803E75D0(u8 *dst, const u8 *src, s32 flags);

u8 fn_803DCE4C(u8 *arg0) {
    u8 buf[24];
    u8 sum;
    u16 i;

    fn_803E75D0(buf, arg0 + 0x20E, 0);
    sum = 0;
    for (i = 0; i < 11; i++) {
        sum = (u8)((sum >> 1) + ((sum & 1) ? 0x80 : 0) + buf[i]);
    }
    return sum;
}

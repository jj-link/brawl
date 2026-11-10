#include <types.h>
#pragma force_active on

extern char lbl_8053B248[];
extern s32 fn_803BE78C(u8 *, const u8 *, s32);
extern int fn_803BDE80(int, int);
extern s32 fn_803BDEAC(char *, void *, s32);

static inline u8 checksum(u8 *arg0) {
    u8 buf[12];
    u8 sum;
    u16 i;
    fn_803BE78C(buf, arg0 + 0x20E, 0);
    sum = 0;
    for (i = 0; i < 11; i++) {
        sum = (u8)(buf[i] + (sum >> 1) + ((sum & 1) ? 0x80 : 0));
    }
    return sum;
}

s32 fn_803B2100(u8 *arg0, s32 arg1, s32 arg2) {
    s32 result = 1;

    if (arg0[0x20A] != 0 && arg0[0x20B] == 1) {
        if (arg0[0x20C] == checksum(arg0))
            result = fn_803BDE80((int)arg0, arg1) != 0;
    }

    if (result == 1) {
        if ((*(u32 *)(lbl_8053B248 + 0x3C) & 2) == 2 && !(arg2 & 8)) {
            if (fn_803BDEAC((char *)(arg0 + 0x20E), (void *)arg1, 0) == 0)
                result = 0;
        } else if (fn_803BDEAC((char *)(arg0 + 0x20E), (void *)arg1, 1) == 0) {
            result = 0;
        }
    }

    return result;
}

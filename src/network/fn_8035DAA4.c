#include <types.h>
#pragma force_active on
extern u8 lbl_805A4980[4];
extern u8 lbl_805A4984[4];
extern u8 lbl_805A4988[8];
static inline void readChunk(u8 *src, u8 *buf, s32 len) {
    s32 i;
    for (i = 0; i < ((len < 3) ? len : 3); i++) {
        buf[i] = src[i];
    }
    for (; i < 3; i++) {
        buf[i] = 0;
    }
}
void fn_8035DAA4(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3) {
    u8 *table;
    u8 *start;
    u8 *lim;
    s32 len;
    u8 c;
    u8 buf[3];
    start = arg1;
    len = arg2;
    switch (arg3) {
    case 1: table = lbl_805A4984; break;
    case 2: table = lbl_805A4988; break;
    default: table = lbl_805A4980; break;
    }
    while (len > 0) {
        readChunk(arg0, buf, len);
        arg1[0] = buf[0] >> 2;
        arg1[1] = ((buf[1] >> 4) | ((buf[0] & 3) << 4)) & 0x3F;
        arg1[2] = ((buf[2] >> 6) | ((buf[1] & 0xF) << 2)) & 0x3F;
        arg1[3] = buf[2] & 0x3F;
        arg0 += 3;
        len -= 3;
        arg1 += 4;
    }
    lim = arg1;
    if (arg2 % 3 == 1) lim = arg1 - 2;
    else if (arg2 % 3 == 2) lim = arg1 - 1;
    *arg1 = 0;
    while (arg1 > start) {
        arg1--;
        if (arg1 >= lim) *arg1 = table[2];
        else {
            c = *arg1;
            if ((s8)c <= 0x19) *arg1 = c + 0x41;
            else if ((s8)c <= 0x33) *arg1 = c + 0x47;
            else if ((s8)c <= 0x3D) *arg1 = c - 4;
            else if ((s8)c == 0x3E) *arg1 = table[0];
            else if ((s8)c == 0x3F) *arg1 = table[1];
        }
    }
}

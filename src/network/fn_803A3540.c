#pragma force_active on

#include <types.h>

extern s32 lbl_805A1170;

s32 fn_803A3540(u16 *arg0, s32 arg1)
{
    unsigned char *tbl;
    unsigned char *r6;
    unsigned char *r7;
    unsigned char *r4;
    s32 r5;
    s32 off;
    u16 r8;

    tbl = (unsigned char *)lbl_805A1170;
    if (((tbl != 0) ? (tbl + 0x3600) : (unsigned char *)0) == 0) {
        return -9;
    }
    if (arg0 == 0) {
        return -3;
    }
    if (arg1 != 0) {
        *arg0 = 0;
    } else {
        *arg0 += 1;
    }
    r7 = (unsigned char *)lbl_805A1170;
    r4 = (r7 != 0) ? (r7 + 0x3600) : (unsigned char *)0;
    r8 = *arg0;
    if (r8 >= *(u16 *)(r4 + 0x14)) {
        return -0xF;
    }
    r6 = r7 + 0x3600;
    while (r8 < *(u16 *)(((r7 == 0) ? (unsigned char *)0 : r6) + 0x14)) {
        if (r8 >= *(u16 *)(((r7 != 0) ? r6 : (unsigned char *)0) + 0x14) || r8 == 0xFFFF) {
            r5 = -3;
        } else {
            r4 = (r7 != 0) ? r6 : (unsigned char *)0;
            off = (r8 * 0x10) & 0xFFFF0;
            r5 = 0;
            if (*(s32 *)(r4 + off + 0x80) == 0) {
                r5 = -0xD;
            }
        }
        if (r5 >= 0) {
            *arg0 = r8;
            return 0;
        }
        r8++;
    }
    return -0xF;
}

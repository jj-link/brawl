#include <types.h>
#pragma force_active on
extern int fn_803E6CDC(void *, int);
extern int fn_803E6D08(void *, int, int);
extern void fn_803E75D0(void *, void *, int);
extern void fn_803E774C(void *, void *, u8);
extern char lbl_805644C0[];

static inline u8 checksum(u8 *arg0) {
    u8 buf[12];
    u8 sum;
    u16 i;
    fn_803E75D0(buf, arg0 + 0x20E, 0);
    sum = 0;
    for (i = 0; i < 11; i++) {
        sum = (u8)(buf[i] + (sum >> 1) + ((sum & 1) ? 0x80 : 0));
    }
    return sum;
}

int fn_803DC584(u8 *arg0, u8 *arg1, int arg2, unsigned int arg3, unsigned int arg4, unsigned int arg5, int *arg6) {
    int r31;
    int r30 = 1;
    int r5 = 1;
    unsigned int r6 = arg3;
    int t7;
    int t9;

    if ((int)(r6 & 0xF) == 0xF) {
        r30 = 1;
    } else {
        if (r6 == 0) r6 = 0x40;
        if (arg4 & 0x80) {
            t9 = arg4 & 0x7F;
            t7 = arg5 & 0x7F;
            if ((t9 != 0 && t9 != (int)(t9 & r6)) || (t7 != 0 && t7 == (int)(t7 & r6))) r5 = 0;
        } else if (arg4 != 0x7F && r6 != arg4 && (!(r6 & arg4) || (r6 & arg5))) {
            r5 = 0;
        }
        if (r5 == 0) {
            r30 = 1;
        } else {
            r31 = r6 & 8;
            if (r31 != 0) {
                arg0[0x20A] = 0;
                *(short *)arg0 = 0;
            }
            fn_803E774C(arg0 + 0x20E, arg1, arg1[0xB]);
            if (((char *)arg0)[0x20E] == 5) ((char *)arg0)[0x20E] = -0x1B;
            if (arg0[0x20A] != 0 && arg0[0x20B] == 1) {
                if (arg0[0x20C] == checksum(arg0)) {
                    r30 = fn_803E6CDC(arg0, arg2) != 0;
                }
            }
            if (r30 == 1) {
                if ((*(unsigned int *)(lbl_805644C0 + 0x60) & 2) == 2 && r31 == 0) {
                    if (fn_803E6D08(arg0 + 0x20E, arg2, 0) == 0) r30 = 0;
                } else if (fn_803E6D08(arg0 + 0x20E, arg2, 1) == 0) r30 = 0;
            }
            if (r30 == 1) *arg6 += 1;
        }
    }
    return r30;
}
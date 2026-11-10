#include <types.h>
#pragma force_active on

extern s32 fn_8020A710(u8 *, s32, s32);
extern s32 fn_8020AF84(u8 *, s32, s32);
extern void fn_8020B9BC(u8 *, u8 *, s32);
extern s32 fn_8020D250(u8 *);
extern void *fn_803D634C(void *, int, u32);
extern s32 fn_803D6480(const u8 *, const u8 *);

extern u8 lbl_80598098[0x40];
extern u8 lbl_8059FF18[2];
extern u8 lbl_8059FF1C[3];

s32 fn_803EC6E8(u8 *arg0)
{
    u8 sp8[0x10];
    u16 n;
    u8 *p;
    u16 total;
    u8 *dst;
    s32 r;
    s32 t;

    n = 0;
    total = 0;
    if (*(u32 *)(arg0 + 0xE4) & 4) {
        return 0;
    }
    p = arg0 + 4;
    fn_803D634C(sp8, 0, 0x10);
    dst = sp8;
    for (;;) {
        switch ((s8)*p) {
        case 47:
            if (n == 0) {
                if (total == 0) {
                    r = fn_8020D250(lbl_8059FF18);
                    if (r != 0) {
                        return r;
                    }
                }
                p++;
                goto copy;
            }
            if ((s8)p[1] == 0) {
                if (n > 0xC) {
                    return -0x14;
                }
                r = fn_8020A710(sp8, 0x30, 0);
                if (r != 0 && r != -6) {
                    goto done;
                }
                fn_8020B9BC(sp8, arg0 + 0x58, 3);
                return fn_8020D250(lbl_80598098);
            }
            if (n > 0xB) {
                return -0x14;
            }
            if (fn_803D6480(sp8, lbl_8059FF1C) != 0) {
                r = fn_8020AF84(sp8, 0x30, 0);
            } else {
                r = 0;
            }
            if (r == 0 || r == -6 || r == -1) {
                t = fn_8020D250(sp8);
                if (t != 0) {
                    return t;
                }
            } else {
                return r;
            }
            p++;
            fn_803D634C(sp8, 0, 0x10);
            dst = sp8;
            n = 0;
            goto copy;
        case 0:
            if (n > 0xC) {
                return -0x14;
            }
            r = fn_8020A710(sp8, 0x30, 0);
            if (r != 0 && r != -6) {
                goto done;
            }
            fn_8020B9BC(sp8, arg0 + 0x58, 3);
            return fn_8020D250(lbl_80598098);
        default:
        copy:
            *dst = *p;
            n++;
            total++;
            p++;
            dst++;
            break;
        }
    }
done:
    return r;
}

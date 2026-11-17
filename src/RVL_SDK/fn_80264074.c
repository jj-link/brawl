#include <types.h>
#pragma force_active on
#pragma use_lmw_stmw on

extern s32 fn_80260F70(void *, s32, s32);
extern s32 fn_80261004(u16 *, void *);
extern s32 fn_802610A0(u8 *, s32, void *);
extern s32 fn_80261108(u16, void *);
extern s32 fn_80261224(void *);
extern s32 fn_80261234(void *);
extern void *memset(void *, int, unsigned long);

s32 fn_80264074(s32 *arg0, s32 *arg1, s32 arg2, s32 *arg3) {
    u8 sp10[4];
    u16 spC;
    u16 spA;
    u16 sp8;
    s32 r;
    void *r31;

    r31 = (void *)arg3[0];
    if (r31 == 0) {
        return -1;
    }
    memset(r31, 0, 0x19D4);
    r = fn_80260F70(r31, arg2, arg3[2]);
    if (r < 0) {
        return r;
    }
    r = fn_80261004(&sp8, r31);
    if (r < 0) {
        return r;
    }
    if (sp8 != 0xFFD8) {
        return -0x20;
    }

    for (;;) {
        r = fn_80261004(&spA, r31);
        if (r < 0) {
            return r;
        }
        if (spA == 0xFFE1) {
            r = fn_80261004(&spC, r31);
            if (r < 0) {
                return r;
            }
            if (spC < 2) {
                return -0x45;
            }
            r = fn_802610A0(sp10, 4, r31);
            if (r < 0) {
                return r;
            }
            if (sp10[0] == 0x45 && sp10[1] == 0x78 && sp10[2] == 0x69 && sp10[3] == 0x66) {
                *arg0 = fn_80261224(r31) - 8;
                *arg1 = spC + 2;
                return 0;
            }
            return -0x45;
        }
        r = fn_80261004(&spC, r31);
        if (r < 0) {
            return r;
        }
        if (spC < 2) {
            return -0x45;
        }
        spC = spC - 2;
        if (spA >= 0xFFE0 && spA <= 0xFFEF) {
            r = fn_80261108(spC, r31);
            if (r < 0) {
                return r;
            }
        } else {
            switch (spA) {
            case 0xFFC0:
            case 0xFFC2:
            case 0xFFC4:
            case 0xFFDB:
            case 0xFFDC:
            case 0xFFDD:
            case 0xFFFE:
                r = fn_80261108(spC, r31);
                if (r < 0) {
                    return r;
                }
                break;
            case 0xFFDA:
                return -2;
            case 0xFFD9:
                return -2;
            default:
                return -0x2F;
            }
        }
        if (fn_80261234(r31) <= 4) {
            return -2;
        }
    }
}

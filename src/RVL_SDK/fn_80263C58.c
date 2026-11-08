#include <types.h>
#pragma force_active on
#pragma optimization_level 3
#pragma use_lmw_stmw on

extern s32 fn_80261004(u16 *, void *);
extern s32 fn_80260FC0(u8 *, void *);
extern s32 fn_80261108(s32, void *);

s32 fn_80263C58(void *arg0) {
    u8 *base = (u8 *)arg0;
    int i, j, n, hi, lo;
    u8 *entries = base + 0x18;
    u8 *table = base + 0x44;
    u8 *p;
    u16 spA;
    u8 sp8;
    u32 count;
    s32 ret;

    ret = fn_80261004(&spA, arg0);
    if (ret < 0)
        return ret;
    if (spA < 2)
        return -0x51;

    ret = fn_80260FC0(&sp8, arg0);
    if (ret < 0)
        return ret;

    count = sp8;
    base[0x17f7] = count;
    if (count > 4 || count != base[0x17f6])
        return -0x51;

    for (i = 0; i < (int)base[0x17f7]; i++) {
        ret = fn_80260FC0(&sp8, arg0);
        if (ret < 0)
            return ret;

        n = base[0x17f6];
        for (j = 0; j < n; j++) {
            if ((int)entries[j + 0x14] == (int)sp8) {
                entries[i] = (u8)j;
                p = entries + i;
                goto found;
            }
        }
        return -0x51;

    found:
        ret = fn_80260FC0(&sp8, arg0);
        if (ret < 0)
            return ret;

        hi = sp8 >> 4;
        lo = sp8 & 0xF;
        if (hi > 1 || lo > 1)
            return -0x51;

        entries[p[0] + 0x1c] = (u8)hi;
        entries[p[0] + 0x20] = (u8)lo;

        if (table[hi + 0x1794] != 1)
            return -0x40;
        if (table[lo + 0x1796] != 1)
            return -0x40;
        if (table[p[0x18] + 0x1790] != 1)
            return -0x41;
    }

    ret = fn_80261108(3, arg0);
    return ret & (ret >> 31);
}

#include <types.h>
#pragma force_active on

extern s32 fn_803AA598(char *);
extern s32 fn_803AFBB8(char *);
extern s32 fn_803C2E94(s32 *);
extern s32 fn_803AA858(char *, s32);
extern s32 fn_803B35D0(char *, char *);
extern s32 fn_803B7C98(char *);
extern s32 fn_803B3678(char *);
extern char lbl_8053B248[];

static inline s32 scan_slots(s32 key) {
    char *p = lbl_8053B248 + 8;
    u32 i;

    for (i = 1; i < 1; i++) {
        s32 t = *(s32 *)(p + 0x40) & 1;
        *(s32 *)(p + 0x40) = t;
        if (t != 0 && key == *(s32 *)(p + 0x44)) {
            return 1;
        }
        p += 8;
    }
    return 0;
}

s32 fn_803C06B8(char *arg0) {
    s32 sp8;
    s32 ret;
    s32 flags;
    char *q;
    u32 i;

    ret = fn_803AA598(arg0);
    if (ret != 0) {
        return ret;
    }
    if (*(u16 *)arg0 == 0 || (*(u16 *)arg0 & 0x1FF) != 0) {
        return 0xF;
    }
    ret = fn_803AFBB8(arg0);
    if (ret != 0) {
        return ret;
    }
    flags = *(u16 *)(arg0 + 0x1878) | 2;
    *(u16 *)(arg0 + 0x1878) = flags;
    if ((flags & 2) == 0) {
        ret = 9;
    } else {
        fn_803C2E94(&sp8);
        *(s32 *)(arg0 + 0x1618) |= 1;
        if (scan_slots(sp8)) {
            *(s32 *)(arg0 + 0x1860) |= 1;
            *(s32 *)(arg0 + 0x1864) = sp8;
        }
        q = arg0 + 0x1620;
        i = 0;
        while (i < 1) {
            s32 r = fn_803B35D0(arg0, q);
            if (r != 0) {
                ret = r;
                goto done;
            }
            i++;
            q += 0x248;
        }
        ret = 0;
    }
done:
    if (ret == 0 && (*(u16 *)(arg0 + 0x1878) & 0x10)) {
        ret = fn_803AA858(arg0, *(s32 *)(arg0 + 0x1894));
        if (ret == 0 && !(*(u16 *)(arg0 + 0x1878) & 0x20)) {
            ret = fn_803B7C98(arg0);
            if (ret == 0) {
                ret = fn_803B3678(arg0);
            }
        }
    }
    if (ret != 0) {
        *(u16 *)(arg0 + 0x1878) &= ~2;
    }
    return ret;
}

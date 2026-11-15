#pragma force_active on
#include <types.h>

extern char lbl_80529CF8[];
extern char lbl_80480958[];

extern int fn_803F6150(const void *, const void *, unsigned long);
extern void fn_802319E4(int, const char *);
extern u8 fn_8023DB4C(void *, u8 *);
extern u8 fn_8023D97C(int, void *, void *);
extern void *fn_8023A0F0(void *);
extern u8 fn_8023F304(void *);
extern u8 fn_80245304(u16, int);
extern u8 fn_80245BFC(void *, u32);
extern void *memcpy(void *, const void *, unsigned long);
extern void *memset(void *, int, unsigned long);

static inline u8 *find_entry(void *addr)
{
    u8 *e = (u8 *)lbl_80529CF8 + 0x34;
    u32 i;
    for (i = 0; i < 4; i++, e += 0x11C) {
        if (e[0x119] != 0 && fn_803F6150(e + 8, addr, 6) == 0) {
            return e;
        }
    }
    return 0;
}

u8 fn_802383DC(void *arg0, u32 arg1, u32 arg2)
{
    u8 buf[0x10];
    u8 *e;
    u8 r;
    void *p;

    if (!(lbl_80529CF8[0x640] & 0x20)) {
        return 4;
    }

    e = find_entry(arg0);

    if (e == 0) {
        return 7;
    }
    if (e[0x11A] == arg1) {
        return 0;
    }
    if (fn_8023F304(arg0) == 1) {
        return 3;
    }
    if (e[0x11B] != 0) {
        if ((u8)lbl_80529CF8[0x27C0] >= 5) {
            fn_802319E4(0xD0004, lbl_80480958);
        }
        return 2;
    }

    memset(lbl_80529CF8 + 0x624, 0, 8);
    r = fn_8023DB4C(e + 8, buf);
    if (r != 0) {
        return r;
    }
    if ((u8)(buf[0] + 0xFE) <= 1) {
        buf[12] = 0;
        if (fn_8023D97C(0x80, e + 8, buf + 4) != 1) {
            return 6;
        }
        e[0x11B] = 1;
        goto done;
    }
    p = fn_8023A0F0(arg0);
    if (p != 0 && (((u8 *)p)[0x76] & 4)) {
        if (fn_80245304(*(u16 *)e, 0) == 0) {
            return 3;
        }
        e[0x11B] = 2;
        goto done;
    }
    if (fn_80245BFC(arg0, arg1) == 0) {
        return 3;
    }
    e[0x11B] = 5;

done:
    memcpy(lbl_80529CF8 + 0x626, arg0, 6);
    lbl_80529CF8[0x625] = (char)arg1;
    *(u32 *)(lbl_80529CF8 + 0x62C) = arg2;
    return 1;
}

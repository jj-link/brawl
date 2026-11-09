#include <types.h>
#pragma force_active on
extern u8 *fn_8023B434(void);
extern void fn_802319FC(int, void *, int);
extern s32 fn_80245CAC(s32, s32);
extern int fn_803F6150(const void *, const void *, unsigned long);
extern u8 lbl_804808F8[];
extern u8 lbl_80529CF8[];
s32 fn_80238768(void *arg0, u16 *arg1) {
    u8 *base = lbl_804808F8;
    u8 *p;
    u32 i;
    u8 *found;
    u8 *entry;
    u16 t;
    u16 v;
    p = fn_8023B434();
    t = *arg1;
    if (t != 0) {
        if ((t & 1) && !(p[0] & 0x20)) {
            *arg1 = t & 0xFFFE;
            if (lbl_80529CF8[0x27C0] >= 3)
                fn_802319FC(0xD0002, base + 0xBC, *arg1);
        }
        t = *arg1;
        if ((t & 2) && !(p[0] & 0x40)) {
            v = t & 0xFFFFFFFD;
            *arg1 = v;
            if (lbl_80529CF8[0x27C0] >= 3)
                fn_802319FC(0xD0002, base + 0xF8, v);
        }
        t = *arg1;
        if ((t & 4) && !(p[0] & 0x80)) {
            v = t & 0xFFFFFFFB;
            *arg1 = v;
            if (lbl_80529CF8[0x27C0] >= 3)
                fn_802319FC(0xD0002, base + 0x130, v);
        }
        t = *arg1;
        if ((t & 8) && !(p[1] & 1)) {
            v = t & 0xFFFFFFF7;
            *arg1 = v;
            if (lbl_80529CF8[0x27C0] >= 3)
                fn_802319FC(0xD0002, base + 0x170, v);
        }
    }
    i = 0;
    entry = lbl_80529CF8 + 0x34;
    for (;;) {
        if (entry[0x119] != 0 && fn_803F6150(entry + 8, arg0, 6) == 0) {
            found = entry;
            break;
        }
        i++;
        entry += 0x11C;
        if (i >= 4) {
            found = 0;
            break;
        }
    }
    if (found != 0) {
        if ((u8)fn_80245CAC(*(u16 *)found, *arg1) != 0)
            return 1;
        return 3;
    }
    return 7;
}
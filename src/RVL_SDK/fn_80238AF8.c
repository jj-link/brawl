#include <types.h>
#include <string.h>
#pragma force_active on

extern u8 lbl_80529CF8[];
extern u8 lbl_80480938[];
extern void fn_802319FC(s32, void *, u32);
extern u8 *fn_8023A038(u32);
extern s32 fn_80238768(void *, u16 *);
extern s32 fn_802451F8(s32, u32);
extern s32 fn_802466F8(s32, u32);
extern int fn_803F6150(const void *, const void *, unsigned long);

void fn_80238AF8(u8 *arg0) {
    u8 *p = lbl_80529CF8 + 0x34;
    u16 key;
    u32 i;
    u8 *t;
    u16 t5;
    u16 r4v;
    u16 val;
    u32 j;
    u8 *q;
    u8 *found;
    u16 r28v;
    u8 lvl;
    void (*fp)(void *, void *, void *, void *, s32);

    if (arg0[0] != 0) {
        return;
    }
    key = (u16)(arg0[1] + (arg0[2] << 8));
    for (i = 0; i < 4; i++) {
        if (p[0x119] != 0 && *(u16 *)p == key) {
            p[0x110] = arg0[3];
            p[0x111] = arg0[4];
            p[0x112] = arg0[5];
            p[0x113] = arg0[6];
            p[0x114] = arg0[7];
            p[0x115] = arg0[8];
            p[0x116] = arg0[9];
            p[0x117] = arg0[10];
            t = fn_8023A038(key);
            if (t != 0) {
                memcpy(t + 0x77, p + 0x110, 8);
            }
            t5 = *(u16 *)(lbl_80529CF8 + 0x654);
            lvl = lbl_80529CF8[0x636];
            r4v = t5 & 0xCC18;
            if (lvl >= 3) {
                val = r4v | (t5 & 0x3306);
            } else {
                val = r4v & ~0x3306;
            }
            if (lbl_80529CF8[0x27C0] >= 4) {
                fn_802319FC(0xD0003, lbl_80480938, val);
            }
            if ((u8)fn_802451F8(*(u16 *)p, val) != 0) {
                *(u16 *)(p + 2) = val;
            }
            if (*(u16 *)(lbl_80529CF8 + 0x4C4) != 0) {
                fn_80238768(p + 8, (u16 *)(lbl_80529CF8 + 0x4C4));
            }
            j = 0;
            r28v = *(u16 *)(lbl_80529CF8 + 0x4C6);
            q = lbl_80529CF8 + 0x34;
            for (;;) {
                if (q[0x119] != 0 && fn_803F6150(q + 8, p + 8, 6) == 0) {
                    found = q;
                    break;
                }
                j++;
                q += 0x11C;
                if (j >= 4) {
                    found = 0;
                    break;
                }
            }
            if (found != 0) {
                *(u16 *)(found + 0x10E) = r28v;
                if (found[0x11A] == 0) {
                    fn_802466F8(*(u16 *)found, r28v);
                }
            }
            fp = *(void (**)(void *, void *, void *, void *, s32))(lbl_80529CF8 + 0x4C8);
            if (fp != 0) {
                fp(p + 8, p + 0xE, p + 0x11, p + 0x110, 1);
            }
            return;
        }
        p += 0x11C;
    }
}
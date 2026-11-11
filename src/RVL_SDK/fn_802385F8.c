#pragma force_active on
#include <types.h>

extern u8 lbl_80529CF8[];
extern u8 fn_80245BFC(void *arg0, u8 arg1);

void fn_802385F8(u32 arg0, u32 arg1, s32 arg2) {
    u8 *base;
    u32 idx;
    u8 *p;
    u8 state;
    void (*fn)(void *);

    base = lbl_80529CF8;
    idx = 0;
    if (base[0x14D] != 0 && *(u16 *)(base + 0x34) == arg0) goto found;
    idx = 1;
    if (base[0x269] != 0 && *(u16 *)(base + 0x150) == arg0) goto found;
    idx = 2;
    if (base[0x385] != 0 && *(u16 *)(base + 0x26C) == arg0) goto found;
    idx = 3;
    if (base[0x4A1] != 0 && *(u16 *)(base + 0x388) == arg0) goto found;
    idx = 4;
found:
    if (idx < 4) {
        p = lbl_80529CF8 + idx * 0x11C;
        goto body;
    } else {
        return;
    }
body:
    state = p[0x14F];
    if (state == 2) {
        if (arg2 != 0) {
            p[0x14F] = 0;
        } else {
            p[0x14F] = 3;
        }
        if (fn_80245BFC(p + 0x3C, (u8)(p[0x14E] == 0)) == 0) {
            p[0x14F] = 0;
            fn = *(void (**)(void *))(lbl_80529CF8 + 0x62C);
            if (fn != 0) {
                fn(lbl_80529CF8 + 0x624);
                *(u32 *)(lbl_80529CF8 + 0x62C) = 0;
            }
        }
    } else if (state == 4) {
        p[0x14F] = 0;
        fn = *(void (**)(void *))(lbl_80529CF8 + 0x62C);
        if (fn != 0) {
            fn(lbl_80529CF8 + 0x624);
            *(u32 *)(lbl_80529CF8 + 0x62C) = 0;
        }
    }
}

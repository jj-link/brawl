#include <types.h>
#pragma force_active on

extern u8 lbl_805297D0[];
extern u8 lbl_80529CF8[];
extern void *fn_8022EFF8(int);
extern void fn_8022F500(void *, void *);
extern void *fn_8022F77C(void *);
extern void fn_80231844(void *, short);
extern void fn_80231FB0(void *, int, int);
extern void *memcpy(void *, const void *, unsigned long);

void fn_80242908(u8 *p) {
    u8 *q;
    u8 *t;
    u16 id;

    if (p != 0 && *(u16 *)(lbl_805297D0 + 0x6C) != 0) {
        fn_8022F500(lbl_805297D0 + 0x64, p);
        p = 0;
    }
    if (*(u16 *)(lbl_805297D0 + 0x80) == 0 && lbl_80529CF8[0x64E] == 0) {
        *(u16 *)(lbl_805297D0 + 0x80) = *(u16 *)(lbl_805297D0 + 0x6C) + 1;
    }
    while (*(u16 *)(lbl_805297D0 + 0x80) != 0) {
        if (p == 0) {
            p = fn_8022F77C(lbl_805297D0 + 0x64);
        }
        if (p == 0) break;
        t = p + *(u16 *)(p + 4);
        id = (u16)(t[8] + (t[9] << 8));
        if (id != 0xC03 && id != 0xC35) {
            q = fn_8022EFF8(2);
            if (q != 0) {
                memcpy(q, p, 8);
                memcpy(q + *(u16 *)(q + 4) + 8, p + *(u16 *)(p + 4) + 8, *(u16 *)(p + 2));
                fn_8022F500(lbl_805297D0 + 0x70, q);
                fn_80231FB0(lbl_805297D0 + 0x4C, 0x3C, 8);
            }
        }
        (*(u16 *)(lbl_805297D0 + 0x80))--;
        fn_80231844(p, 0x2000);
        p = 0;
    }
    if (p != 0) {
        fn_8022F500(lbl_805297D0 + 0x64, p);
    }
}

#include <types.h>
#pragma force_active on

extern char lbl_8053B248[];
extern char lbl_8059FE7C;
extern char lbl_8059FE84;

extern s32 fn_803A9884(void *dst, void *src);
extern s32 fn_803A98A8(void *a, void *b);
extern u32 fn_803A9A78(void *p);
extern s32 fn_803A9D54(void *a, void *b);
extern char *fn_803AA01C(void *dst, void *src);
extern void fn_803BEE24(void *a, void *b);

void fn_803BF90C(void *arg0, void *arg1, void *arg2) {
    s16 sp8[2];

    if (fn_803A9A78(arg2) == 1U) {
        if (fn_803A98A8(*(char **)arg2, &lbl_8059FE84) == 0) {
            fn_803A9884(arg0, &lbl_8059FE7C);
            return;
        }
        fn_803A9884(arg0, *(char **)arg2);
        return;
    }
    if (fn_803A9D54(arg2, &lbl_8059FE84) == 0) {
        sp8[0] = 0x2A;
        sp8[1] = 0;
        fn_803AA01C(arg1, sp8);
    } else {
        fn_803AA01C(arg1, *(char **)arg2);
    }
    if ((*(u32 *)(lbl_8053B248 + 0x3C) & 2) == 2) {
        *(u32 *)(lbl_8053B248 + 0x3C) = (*(u32 *)(lbl_8053B248 + 0x3C) & ~3) | 1;
        fn_803BEE24(arg0, arg1);
        *(u32 *)(lbl_8053B248 + 0x3C) = (*(u32 *)(lbl_8053B248 + 0x3C) & ~3) | 2;
        return;
    }
    fn_803BEE24(arg0, arg1);
}

#include <types.h>
#pragma force_active on

extern void fn_8035E00C(void *p);
extern void fn_8036A028(s32 a, void *b, s32 c);

void fn_8036AC80(s32 arg0, void *arg1) {
    s32 type;
    u8 *r31;
    s32 a;
    s32 b;
    s32 c;

    r31 = (u8 *)arg1;
    ((void (*)(s32, void *, void *))(*(void **)r31))(arg0, *(void **)(r31 + 8), *(void **)(r31 + 4));
    type = *(s32 *)(r31 + 0xC);

    if (type == 2) {
        fn_8035E00C(*(void **)(*(u8 **)(r31 + 8) + 8));
        *(void **)(*(u8 **)(r31 + 8) + 8) = 0;
    } else if (type == 11) {
        fn_8035E00C(*(void **)(*(u8 **)(r31 + 8) + 8));
        *(void **)(*(u8 **)(r31 + 8) + 8) = 0;
    } else if (type == 3) {
        a = *(s32 *)(r31 + 8);
        b = 0;
        c = 0;
        while (b < *(s32 *)(a + 0x38)) {
            fn_8035E00C(*(void **)(*(s32 *)(a + 0x3C) + c));
            *(void **)(*(s32 *)(a + 0x3C) + c) = 0;
            fn_8035E00C(*(void **)(*(s32 *)(a + 0x40) + c));
            b++;
            *(void **)(*(s32 *)(a + 0x40) + c) = 0;
            c += 4;
        }
        fn_8035E00C(*(void **)(a + 0x3C));
        *(s32 *)(a + 0x3C) = 0;
        fn_8035E00C(*(void **)(a + 0x40));
        *(s32 *)(a + 0x40) = 0;
    } else if (type == 4) {
        c = *(s32 *)(r31 + 8);
        fn_8035E00C(*(void **)(c + 0xC));
        *(s32 *)(c + 0xC) = 0;
    } else if (type == 7) {
        c = *(s32 *)(r31 + 8);
        if (*(s32 *)(c + 0x10) != 0) {
            fn_8035E00C(*(void **)(c + 0x10));
            *(s32 *)(c + 0x10) = 0;
        }
    } else if (type == 8) {
        c = *(s32 *)(r31 + 8);
        if (*(s32 *)(c + 0x8) != 0) {
            fn_8035E00C(*(void **)(c + 0x8));
            *(s32 *)(c + 0x8) = 0;
        }
    } else if (type == 9) {
        b = *(s32 *)(r31 + 8);
        c = 0;
        a = 0;
        while (c < *(s32 *)(b + 0x4)) {
            fn_8035E00C(*(void **)(*(s32 *)(b + 0x8) + a));
            c++;
            *(void **)(*(s32 *)(b + 0x8) + a) = 0;
            a += 4;
        }
        fn_8035E00C(*(void **)(b + 0x8));
        *(s32 *)(b + 0x8) = 0;
    } else if (type == 12) {
        fn_8036A028(arg0, *(void **)(*(u8 **)(r31 + 8)), 0);
    }

    fn_8035E00C(*(void **)(r31 + 8));
    *(void **)(r31 + 8) = 0;
    fn_8035E00C(r31);
}

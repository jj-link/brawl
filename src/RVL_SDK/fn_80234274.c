#pragma force_active on

typedef unsigned char u8;
typedef unsigned short u16;

extern void fn_802319E4(int id, const char *msg);
extern void fn_80232034(u8 *dst, const u8 *src);
extern int fn_80232068(void *a, void *b);
extern void fn_802324FC(int a, int b, int c);
extern int fn_8023251C(void *a);
extern void fn_80233970(void);
extern u16 fn_80238E0C(void);
extern signed char fn_80238E68(void);
extern void fn_802344F4(void);
extern void *memcpy(void *dst, const void *src, unsigned int n);
extern unsigned char lbl_8047FD20[];
extern unsigned char lbl_80529994[];
extern unsigned char lbl_80529918[];
extern unsigned char lbl_805A0D30;

void fn_80234274(u8 *arg0) {
    u8 sp8[0x118];
    u8 i;
    u8 *p;

    p = arg0 + 0xB;
    if (arg0[0xA] != 0) {
        for (i = 0; i < lbl_80529994[0x4D]; i++) {
            if (fn_80232068(&lbl_80529994[i * 11], p) == 0) {
                break;
            }
        }
        if (i == lbl_80529994[0x4D]) {
            fn_80232034(&lbl_80529994[lbl_80529994[0x4D] * 11], p);
            lbl_80529994[0x4D]++;
        }
        {
            u8 *slot = (u8 *)((unsigned int)lbl_80529994 + i * 11);
            slot[6] = 1;
            slot[7] = 0;
        }
        fn_80232034(sp8, p);
        ((void (*)(int, void *))(*(void **)(lbl_80529994 + 0x50)))(5, sp8);
    } else {
        for (i = 0; i < lbl_80529994[0x4D]; i++) {
            if (fn_80232068(&lbl_80529994[i * 11], p) == 0) {
                for (; i < lbl_80529994[0x4D]; i++) {
                    memcpy(&lbl_80529994[i * 11],
                           &lbl_80529994[(i + 1) * 11], 11);
                }
                break;
            }
        }
        lbl_80529994[0x4D]--;

        if (lbl_80529918[0x78] != 0 &&
            fn_80232068(&lbl_80529918[0x1A], p) == 0) {
            lbl_80529918[0x78] = 0;
            if (lbl_80529918[0x79] != 0) {
                if (lbl_805A0D30 >= 4) {
                    fn_802319E4(0x503, (const char *)lbl_8047FD20);
                }
                fn_8023251C((void *)(lbl_80529918 + 0x40));
                fn_80233970();
            }
        }

        if (lbl_80529994[0x72] != 0 && fn_80238E0C() == 0) {
            lbl_80529994[0x72] = 0;
            fn_8023251C((void *)(lbl_80529994 + 0x74));
            *(void (**)(void))(lbl_80529994 + 0x7C) = fn_802344F4;
            fn_802324FC((int)lbl_80529994 + 0x74, 0, 0x3E8);
        }

        fn_80232034(sp8, p);
        sp8[6] = fn_80238E68();
        ((void (*)(int, void *, void *))(*(void **)(lbl_80529994 + 0x50)))(
            6, sp8, lbl_80529994);
    }
}

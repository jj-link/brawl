#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;

extern char lbl_80529AC8[];
extern char lbl_8047FE88[];
extern char lbl_8047FEB8[];
extern u8 *lbl_8059EDC8;
extern u8 lbl_805A0D30;
extern void *fn_8022EE58(u16);
extern void fn_802319E4(int, const char *);
extern void fn_802319FC(int, const char *, u8);
extern void fn_80232780(void *);
extern void fn_80237600(void *, int, u8 *);
extern void fn_80237D10(void *, u8, int, void *, u8, u8);
extern u8 fn_80247544(void *, void *, u16, void (*)(int, u16, u8 *));
extern u8 fn_80247C00(void *, u16, u8 *);
extern void fn_80235E04(int, u16, u8 *);

void fn_80235F38(void *arg0, void *arg1) {
    u8 sp9;
    u8 sp8;
    void *temp;
    u8 result;
    u8 *a = arg0;
    u8 *b = arg1;

    sp9 = 0x10;
    a[0x14] = b[0xE];
    a[0x1B] = b[0xF];
    if (a[0x15] != 0) {
        sp9 = 0;
        if (lbl_805A0D30 >= 5) {
            fn_802319E4(0x504, lbl_8047FE88);
        }
        if (a[0x16] == 0xFF) {
            result = fn_80247C00(a + 8, *(u16 *)(a + 0xE), &sp8);
            sp9 = result;
            if (result == 0) {
                fn_80237D10(a, sp8, *(u16 *)(a + 0xE), 0, a[0x13], a[0x15]);
                *(u8 *)(lbl_80529AC8 + sp8 + 0x214) = a[0x12];
            }
        }
        fn_80237600(a, 0x1707, &sp9);
        return;
    }
    if (*(void **)(lbl_80529AC8 + 0x228) == 0) {
        temp = fn_8022EE58(*(u16 *)(lbl_8059EDC8 + 8));
        *(void **)(lbl_80529AC8 + 0x228) = temp;
        *(void **)(lbl_80529AC8 + 0x210) = a;
        result = fn_80247544(b + 8, temp, *(u16 *)(lbl_8059EDC8 + 8), fn_80235E04);
        sp9 = result;
        if (result != 0) {
            if (lbl_805A0D30 >= 5) {
                fn_802319FC(0x504, lbl_8047FEB8, result);
            }
            sp9 = 7;
            fn_80232780(lbl_80529AC8 + 0x228);
        }
    }
    if (sp9 != 0) {
        fn_80237600(a, 0x1707, &sp9);
    }
}

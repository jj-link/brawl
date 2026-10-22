#pragma force_active on
extern unsigned char lbl_805A0D30;
extern unsigned char lbl_8047FCA0[];
extern unsigned char lbl_80529994[];
extern void fn_802319E4(int id, const char *msg);
extern unsigned short fn_80238E0C(void);
extern void fn_80239968(void *p);

void fn_80232984(void) {
    unsigned char i;

    if (lbl_805A0D30 >= 4) {
        fn_802319E4(0x503, (const char *)lbl_8047FCA0);
    }
    if (fn_80238E0C() != 0 && lbl_80529994[0x101] == 0) {
        for (i = 0; i < lbl_80529994[0x4D]; i++) {
            fn_80239968(lbl_80529994 + i * 11);
        }
        return;
    }
    lbl_80529994[0x72] = 0;
    ((void (*)(int, int, void *))(*(void **)(lbl_80529994 + 0x50)))(1, 0, lbl_80529994);
}

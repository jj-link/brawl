#pragma force_active on
extern unsigned char lbl_805A0D30;
extern void fn_802319E4(int, const char *);
extern void fn_80233970(void *);
extern const char lbl_8047FCC0[];
extern unsigned char lbl_80529918[];

void fn_802335B4(void) {
    if (lbl_805A0D30 >= 4) {
        fn_802319E4(0x503, lbl_8047FCC0);
    }
    lbl_80529918[0x78] = 0;
    fn_80233970(lbl_80529918);
}

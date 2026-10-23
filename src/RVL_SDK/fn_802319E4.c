#pragma force_active on

extern unsigned char lbl_805A0D20;
extern void fn_80231928(int, ...);

void fn_802319E4(void) {
    int x;
    if (lbl_805A0D20 == 0) {
        fn_80231928(x);
    }
}

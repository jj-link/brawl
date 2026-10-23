#pragma force_active on
extern unsigned char lbl_805A0D20;
extern void fn_80231928(int, ...);

void fn_80231A5C(int arg0) {
    if (lbl_805A0D20 == 0) {
        fn_80231928(arg0);
    }
}

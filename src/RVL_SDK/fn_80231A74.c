#pragma force_active on

extern unsigned char lbl_805A0D20;
extern void fn_80231928(...);

void fn_80231A74(void) {
    if (lbl_805A0D20 == 0) {
        fn_80231928();
    }
}

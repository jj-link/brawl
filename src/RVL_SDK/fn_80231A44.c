#pragma force_active on

extern unsigned char lbl_805A0D20;
extern void fn_80231928(...);

void fn_80231A44(void) {
    if (!lbl_805A0D20) {
        fn_80231928();
        return;
    }
}

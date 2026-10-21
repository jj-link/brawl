#pragma force_active on
extern int lbl_805A0FA0;
extern int lbl_805A0FA4;
extern void fn_80385CC4(void);

void fn_8033C0D4(void) {
    if (lbl_805A0FA0 == 0) {
        fn_80385CC4();
        return;
    }
    lbl_805A0FA4 = 1;
}

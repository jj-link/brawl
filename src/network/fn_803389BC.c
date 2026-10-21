#pragma force_active on
extern int fn_80352AB8(void);
extern void fn_803522DC(void);
extern void *lbl_805A0F80;

void fn_803389BC(void) {
    if (fn_80352AB8() == 0) {
        fn_803522DC();
    }
    lbl_805A0F80 = 0;
}

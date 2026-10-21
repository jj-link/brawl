#pragma force_active on
extern int lbl_805A0938;
extern void fn_801F94DC(void);
extern void fn_801FE768(void (*callback)(void));

void fn_801F9664(void) {
    if (lbl_805A0938 == 0) {
        lbl_805A0938 = 1;
        fn_801FE768(fn_801F94DC);
    }
}

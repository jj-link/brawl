#pragma force_active on
extern void fn_8035E00C(void*);
extern void fn_8037BE70(void);
extern void fn_8037BE74(void);
extern void fn_8037BE78(void);
extern void fn_8037C960(void);
extern void* lbl_805A1064;
extern int lbl_805A1078;

void fn_8037EAA0(void) {
    fn_8037BE74();
    if (--lbl_805A1078 == 0) {
        fn_8037C960();
        if (lbl_805A1064 != 0) {
            fn_8035E00C(lbl_805A1064);
            lbl_805A1064 = 0;
        }
        fn_8037BE78();
        fn_8037BE70();
    } else {
        fn_8037BE78();
    }
}

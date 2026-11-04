#pragma force_active on
extern void fn_8037BE74(void);
extern void fn_8037BE78(void);
extern void fn_8037C5AC(void *);
extern void fn_8035E00C(void *);
extern int lbl_805A106C;
extern int lbl_805A1070;
extern char *lbl_805A1074;

void fn_8037C960(void)
{
    int off;
    int i;
    if (lbl_805A1074 != 0) {
        if (lbl_805A106C > 0) {
            fn_8037BE74();
            for (i = 0, off = 0; i < lbl_805A1070; off += 4, i++) {
                void *p = *(void **)(lbl_805A1074 + off);
                if (*(int *)p != 0) {
                    fn_8037C5AC(p);
                }
            }
            fn_8037BE78();
        }
        for (off = 0, i = 0; off < lbl_805A1070; i += 4, off++) {
            fn_8035E00C(*(void **)(lbl_805A1074 + i));
        }
        fn_8035E00C(lbl_805A1074);
        lbl_805A1074 = 0;
        lbl_805A1070 = 0;
        lbl_805A106C = 0;
    }
}
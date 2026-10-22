#pragma force_active on
extern void fn_8037BE74(void);
extern void fn_8037BE78(void);
extern int lbl_805A106C;
extern int lbl_805A1070;
extern char* lbl_805A1074;

void fn_8037C790(void (*arg0)(void))
{
    int off;
    int i;

    if (lbl_805A106C > 0) {
        fn_8037BE74();
        for (i = 0, off = 0; i < lbl_805A1070; off += 4, i++) {
            void* p = *(void**)(lbl_805A1074 + off);
            if (*(int*)p != 0) {
                arg0();
            }
        }
        fn_8037BE78();
    }
}

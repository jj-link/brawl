#pragma force_active on
extern void fn_8037BE74(void);
extern void fn_8037BE78(void);
extern int lbl_805A1070;
extern int **lbl_805A1074;

int *fn_8037C720(int arg0) {
    int *var_r31;

    fn_8037BE74();
    if (arg0 < 0 || arg0 >= lbl_805A1070) {
        fn_8037BE78();
        return 0;
    }
    var_r31 = lbl_805A1074[arg0];
    if (*var_r31 == 0) {
        var_r31 = 0;
    }
    fn_8037BE78();
    return var_r31;
}

#pragma force_active on
extern int fn_8039A274(void);
extern void fn_8039C16C(int, int, int);

void fn_8039B5AC(int arg0, int arg1) {
    int var_r31;

    var_r31 = 1;
    if (fn_8039A274() != 0) {
        var_r31 = 0;
    }
    fn_8039C16C(arg0, arg1, var_r31);
}

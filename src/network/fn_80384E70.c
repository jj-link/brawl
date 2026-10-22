#pragma force_active on
extern int *fn_803822D8(int, int, int, int *);
extern void *lbl_805A10B0;

int fn_80384E70(void *arg0, int arg1, int *(*arg2)(int, int, int *), int arg3) {
    int sp8;
    int *var_r3;

    sp8 = arg3;
    if (arg0 == 0) {
        arg0 = lbl_805A10B0;
    }
    if (arg0 == 0) {
        var_r3 = &sp8;
    } else {
        var_r3 = arg2(((int *)arg0)[3], arg1, &sp8);
        if (var_r3 == 0) {
            var_r3 = fn_803822D8(((int *)arg0)[3], arg1, 0, &sp8);
        }
    }
    return *var_r3;
}

#pragma force_active on

extern double *fn_803822D8(int, int, int, double *);
extern void *lbl_805A10B0;

double fn_80384EFC(void *arg0, int arg1, double *(*arg2)(int, int, double *), double farg0) {
    double sp8;
    void *var_r30;
    double *result;

    sp8 = farg0;
    if (arg0 == 0) {
        arg0 = lbl_805A10B0;
    }
    var_r30 = arg0;
    if (var_r30 == 0) {
        result = &sp8;
    } else {
        result = arg2(*(int *)((char *)var_r30 + 0xC), arg1, &sp8);
        if (result == 0) {
            result = fn_803822D8(*(int *)((char *)var_r30 + 0xC), arg1, 1, &sp8);
        }
    }
    return *result;
}

#pragma force_active on
extern int fn_803822D8(int, int, int, int);
extern void *lbl_805A10B0;

int fn_80384F88(void *arg0, int arg1, int (*arg2)(int, int, int), int arg3) {
    int ret;

    if (arg0 == 0) {
        arg0 = lbl_805A10B0;
    }
    if (arg0 == 0) {
        return arg3;
    }
    ret = arg2(((int *)arg0)[3], arg1, arg3);
    if (ret == 0) {
        ret = fn_803822D8(((int *)arg0)[3], arg1, 2, arg3);
    }
    return ret;
}

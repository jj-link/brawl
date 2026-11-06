#pragma force_active on
extern int lbl_805A1310;
extern int fn_8025FBB8(void *, unsigned int);
int gdev_cc_write(char *arg0, int arg1) {
    int n;
    if (lbl_805A1310 == 0) return -10001;
    while (arg1 > 0) {
        n = fn_8025FBB8(arg0, arg1);
        if (n == 0) break;
        arg0 += n;
        arg1 -= n;
    }
    return 0;
}
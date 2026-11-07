#pragma force_active on
extern int fn_803A28F4(int, int *);
extern int fn_80212C08(int, int, void *, int, void *, int, int (*)(int, int *), void *);
extern int lbl_805A11C0;

int fn_803A2890(int a, int b, int c, void *d, int e, void *f, int g, void *h) {
    if (fn_80212C08(b, c, d, e, f, g, fn_803A28F4, h) < 0) {
        return -0x2A;
    }
    lbl_805A11C0 = 1;
    return 0;
}

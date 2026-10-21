#pragma force_active on
extern void fn_803E5A50(int, int, int, int, int *);

int fn_803EB6E0(int a, int b, int c, int d) {
    int sp8;

    fn_803E5A50(a, b, c, d, &sp8);
    return sp8;
}

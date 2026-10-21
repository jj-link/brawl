#pragma force_active on
extern int fn_80212D40(int, int, void *, int, void *, int);

int fn_803A2848(int a, int b, int c, void *d, int e, void *f, int g) {
    int t = fn_80212D40(b, c, d, e, f, g);
    int result = 0;
    if (t < 0) {
        result = -0x2A;
    }
    return result;
}

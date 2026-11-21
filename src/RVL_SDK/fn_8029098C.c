#pragma force_active on
#pragma use_lmw_stmw on
extern void fn_80290AC0(void *);
extern void fn_80290AC4(void *);
extern void fn_80290BE4(int, int, int, int, int, int, void *);
extern void fn_80291284(int, int, int, int, int, void *);
extern void fn_802915BC(void *, unsigned char);
extern void fn_80291C70(void *, void *, void *, void *, void *);

static inline void helper(int n, char *g, char *b, char *buf, void **p) {
    int j;
    unsigned char y __attribute__((aligned(4)));
    unsigned char t __attribute__((aligned(4)));
    for (j = 0; j < n; j++) {
        fn_802915BC(&t, (n - 1 - j) != 0);
        y = t;
        fn_80291C70(&y, g, b, buf, p);
        b += 0x4c;
        g += 0x3c0;
    }
}
void fn_8029098C(int n, int a, char *b, int c, int d, int e, int f, char *g) {
    char *q;
    int i;
    void *p;
    char buf[0xc0] __attribute__((aligned(16)));
    fn_80290AC0(buf);
    fn_80290AC4(buf);
    p = buf;
    q = g;
    for (i = 0; i < n; i++) {
        fn_80290BE4(i, a, c, d, e, f, q + 0x240);
        if (i < n - 1)
            fn_80291284(i, c, d, e, f, q + 0x300);
        else
            fn_80290AC4(q + 0x300);
        q += 0x3c0;
    }
    helper(n, g, b, buf, &p);
}

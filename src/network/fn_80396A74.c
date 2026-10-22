#pragma force_active on
extern char lbl_80491778[];
extern char lbl_8059FCBC;
extern void fn_803974FC(void);
extern int fn_80397580(void);
extern char *fn_803970E4(int, int);
extern int fn_80392730(const char *);
extern void fn_8039272C(void *, const char *, int);
extern void fn_80392738(void *, int);
extern int fn_80392EC4(void *, void *);
extern int fn_803F861C(const char *, ...);

int fn_80396A74(int a, const char *b, int c, const char *d, const char *e) {
    char buf[0x48];
    char *p;
    char *base = lbl_80491778;
    int n, l1, l2;
    fn_803974FC();
    p = fn_803970E4(fn_80397580(), a);
    if (p == 0 || b == 0) return -1;
    n = fn_80392730(b);
    if (n > 0x100) {
        fn_803F861C(base + 0x1a0);
        return -1;
    }
    fn_8039272C(p + 0xe0, b, n);
    *(int *)(p + 0x1e0) = c;
    if (d != 0 && e != 0) {
        l1 = fn_80392730(d);
        l2 = fn_80392730(e);
        if (l1 > 0x20) {
            fn_803F861C(base + 0x1c8);
            return -1;
        }
        if (l2 > 0x20) {
            fn_803F861C(base + 0x1ec);
            return -1;
        }
        fn_80392738(buf, 0x41);
        fn_8039272C(buf, d, l1);
        fn_8039272C(&buf[l1], &lbl_8059FCBC, 1);
        fn_8039272C(&buf[l1 + 1], e, l2);
        *(int *)(p + 0x240) = fn_80392EC4(p + 0x1e4, buf);
    }
    *(int *)(p + 0xc) = 1;
    return 0;
}

#pragma force_active on
extern void fn_80392738(void *, int);
extern void fn_8039272C(void *, char *, int);
extern int fn_803A7630(int, void *, unsigned int, int);

int fn_80392420(int a, char *buf, unsigned int len, int d) {
    char tmp[32] __attribute__((aligned(32)));
    unsigned int head = (unsigned int)buf & 31 ? 32 - ((unsigned int)buf & 31) : 0;
    int total = 0;
    unsigned int n;
    int r;
    fn_80392738(tmp, 32);
    if (head != 0) {
        if (head > len) head = len;
        fn_8039272C(tmp, buf, head);
        r = fn_803A7630(a, tmp, head, d);
        if (r > 0) {
            total = r;
            if ((unsigned int)r < head) return r;
            buf += r;
            len -= r;
        } else return r;
    }
    if ((int)len > 0 && (n = len & ~31) != 0) {
        r = fn_803A7630(a, buf, n, d);
        if (r > 0) {
            total += r;
            if ((unsigned int)r < n) return total;
            buf += r;
            len -= r;
        } else {
            if (total > 0) return total;
            return r;
        }
    }
    if ((int)len > 0 && (n = len & 31) != 0) {
        fn_80392738(tmp, 32);
        fn_8039272C(tmp, buf, n);
        r = fn_803A7630(a, tmp, n, d);
        if (r > 0) {
            total += r;
        } else {
            if (total > 0) return total;
            return r;
        }
    }
    return total;
}

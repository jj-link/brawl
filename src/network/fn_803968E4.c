#pragma force_active on
extern void *fn_803974FC(void);
extern void *fn_80397580(void *);
extern void *fn_80397128(void *, void *);
extern int fn_80391D8C(void *, int, void **);

int fn_803968E4(void *a, int b, void **c) {
    void *p = fn_80397128(fn_80397580(fn_803974FC()), a);
    if (p == 0) return -1;
    return fn_80391D8C(p, b, c);
}

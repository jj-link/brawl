#pragma force_active on

extern void *fn_8035DFE8(int);
extern void *memset(void *, int, unsigned long);
extern int fn_8035A460(int, int, void *);
extern void fn_8035E00C(void *);
extern void fn_8037F078(void);

void *fn_8037F11C(void) {
    void *p;
    int result;

    p = fn_8035DFE8(0x1c);
    if (p == 0) {
        return 0;
    }
    memset(p, 0, 0x1c);
    ((int *)p)[6] = 1;
    result = fn_8035A460(0x18, 0, fn_8037F078);
    ((int *)p)[0] = result;
    if (result == 0) {
        fn_8035E00C(p);
        return 0;
    }
    return p;
}

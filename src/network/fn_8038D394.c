#pragma force_active on
extern int fn_8035E848(void);
extern void *fn_8035DFE8(int);
extern void *memset(void *, int, unsigned long);
extern int lbl_805A1048;

int fn_8038D394(void *arg0) {
    void *p;

    if (lbl_805A1048 != 1) {
        return 1;
    }
    if (fn_8035E848() != 0) {
        return 2;
    }
    p = fn_8035DFE8(0x4c);
    if (p == 0) {
        return 3;
    }
    memset(p, 0, 0x4c);
    *(void **)arg0 = p;
    return 0;
}

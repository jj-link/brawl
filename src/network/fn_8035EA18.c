#pragma force_active on

extern void *fn_8035DFE8(int);
extern void *memset(void *, int, unsigned long);

void *fn_8035EA18(void) {
    void *p;

    p = fn_8035DFE8(0x38);
    if (p == 0) {
        return 0;
    }
    memset(p, 0, 0x38);
    *(int *)((char *)p + 0xc) = 1;
    return p;
}

#pragma force_active on
extern void *memcpy(void *dst, const void *src, unsigned long n);

void fn_801D9220(int *p) {
    unsigned int v = *(unsigned int *)0x800030F0;
    if (v >= 0x80000000u) {
        memcpy(p, (const void *)v, 0x1C);
        return;
    }
    *p = 0;
}

#pragma force_active on
void *fn_80397748(void *p, unsigned char c, unsigned long n) {
    unsigned long i;
    for (i = 0; i < n; i++) {
        ((unsigned char *)p)[i] = c;
    }
    return p;
}
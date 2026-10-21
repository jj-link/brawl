#pragma force_active on
int fn_8026D4BC(void *self) {
    int *p = (int *)((char *)self + 0x1648);
    unsigned int v = (unsigned int)*p;
    v = (v + 7) >> 3;
    v = (v + 2) << 3;
    *p = (int)v;
    return 0;
}

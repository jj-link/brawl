#pragma force_active on
extern "C" unsigned int fn_27_1992C0(void *r3) {
    unsigned int val = *(unsigned int *)((char *)r3 + 8);
    return (val >> 13) & 1;
}

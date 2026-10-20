#pragma force_active on
extern "C" unsigned int fn_27_2EBA28(const void *p) {
    unsigned int val = *(const unsigned int *)((const char *)p + 8);
    return (val >> 22) & 1;
}

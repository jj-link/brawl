#pragma force_active on
extern "C" unsigned int fn_27_C9AE8(const void *self) {
    unsigned int val = *(const unsigned int *)((const char *)self + 8);
    return (val >> 25) & 1;
}

#pragma force_active on
extern "C" unsigned int fn_27_1D0A94(const void *ptr) {
    const unsigned int *p = (const unsigned int *)((const unsigned char *)ptr + 8);
    return (*p >> 22) & 1;
}

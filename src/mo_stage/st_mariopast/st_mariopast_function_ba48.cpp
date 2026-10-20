#pragma force_active on
extern "C" unsigned int fn_48_BA48(const unsigned int *ptr) {
    unsigned int val = ptr[2];
    return (val >> 13) & 1;
}

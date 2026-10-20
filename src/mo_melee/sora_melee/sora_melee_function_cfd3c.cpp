#pragma force_active on
struct ftFlagBits {
    unsigned int m0;
    unsigned int m4;
    unsigned int m8;
};

extern "C" unsigned int fn_27_CFD3C(ftFlagBits* bits) {
    return (bits->m8 >> 10) & 1;
}

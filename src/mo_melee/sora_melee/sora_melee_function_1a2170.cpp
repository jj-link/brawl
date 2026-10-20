#pragma force_active on
extern "C" int fn_27_1A2170(const unsigned int *p) {
    unsigned int bits = (p[2] << 5) & 0xFC000000u;
    return (int)bits >> 27;
}

#pragma force_active on
extern "C" int fn_27_1A664C(const unsigned int *p) {
    unsigned int value = p[2] << 10;
    value &= 0xFFE00000u;
    return (int)value >> 22;
}

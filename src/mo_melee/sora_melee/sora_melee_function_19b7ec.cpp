#pragma force_active on
extern "C" int fn_27_19B7EC(const unsigned int* p) {
    unsigned int value = p[2] << 12;
    value &= 0xFE000000u;
    return (int)value >> 26;
}

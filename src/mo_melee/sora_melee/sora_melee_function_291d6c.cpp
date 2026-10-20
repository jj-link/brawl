#pragma force_active on
extern "C" int fn_27_291D6C(const unsigned int* p) {
    unsigned int value = p[2];
    value = (value << 3) & 0xF0000000u;
    return (int)value >> 29;
}

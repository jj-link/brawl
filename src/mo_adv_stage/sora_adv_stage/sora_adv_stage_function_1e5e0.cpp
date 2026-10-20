#pragma force_active on
extern "C" int fn_40_1E5E0(unsigned int *p) {
    unsigned int x = p[2];
    return (int)(((x << 12) | (x >> 20)) & 0xFE000000u) >> 26;
}

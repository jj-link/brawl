#pragma force_active on
extern "C" unsigned char fn_801849D0(unsigned char *base, int index) {
    unsigned char *p = base;
    p += index & 0xFFFFFFFC;
    p += index & 0x3;
    return p[0xD4];
}

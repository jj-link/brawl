#pragma force_active on
unsigned int fn_8027B4F4(unsigned char* base, int idx) {
    unsigned char* p = base + idx * 0x68;
    unsigned int v = p[0x62];
    return (unsigned int)(-v | v) >> 31;
}

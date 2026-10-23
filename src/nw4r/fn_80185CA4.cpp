#pragma force_active on
extern "C" unsigned char fn_80185CA4(unsigned char* base, int index) {
    unsigned char* p = base;
    p += index & 0xFFFFFFFC;
    p += index & 3;
    return p[0xE4];
}

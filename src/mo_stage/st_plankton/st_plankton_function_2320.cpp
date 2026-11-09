#pragma force_active on
extern "C" int fn_74_2320(unsigned char* self, void* unused, int* out1, int* out2) {
    unsigned char i;
    if (self[0xE9B] == 0) return 0;
    for (i = 0; i < 6; i++) {
        unsigned char* p = self + (unsigned char)i * 0x28;
        if (p[0x20C] != 0xE) return 0;
    }
    *out1 = 6;
    *out2 = 4;
    return 1;
}

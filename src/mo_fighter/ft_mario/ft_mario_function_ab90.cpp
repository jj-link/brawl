#pragma force_active on
extern "C" int fn_91_ABE8();

extern "C" float fn_91_AB90(unsigned char* self, int unused, int i, int j) {
    unsigned char* p = self + (fn_91_ABE8() << 6);
    float* table = *reinterpret_cast<float**>(p + (i << 2) - 0x3e70);
    return table[j];
}

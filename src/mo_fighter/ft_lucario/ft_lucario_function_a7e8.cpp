#pragma force_active on
extern "C" int fn_118_A840();

extern "C" float fn_118_A7E8(unsigned char* self, int unused, unsigned int i, unsigned int j) {
    unsigned char* base = self + fn_118_A840() * 0xD4;
    float* table = *reinterpret_cast<float**>(base + (i << 2) - 0x3E70);
    return table[j];
}

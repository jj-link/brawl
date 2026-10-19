#pragma force_active on
extern "C" int fn_99_8EE8();

extern "C" float fn_99_8E90(unsigned char* self, int unused, int i, int j) {
    int k = fn_99_8EE8();
    float** arr = reinterpret_cast<float**>(self + k * 0xa0 - 0x3e70);
    float* table = arr[i];
    return table[j];
}

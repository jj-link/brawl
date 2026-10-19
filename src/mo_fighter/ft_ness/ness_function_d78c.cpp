#pragma force_active on
extern "C" int fn_101_D7E4();

extern "C" float fn_101_D78C(unsigned char* base, int unused, int a, int c) {
    int idx = fn_101_D7E4();
    unsigned char* p = base + idx * 0x8c;
    p = p + a * 4;
    float* arr = *reinterpret_cast<float**>(p - 0x3E70);
    return arr[c];
}

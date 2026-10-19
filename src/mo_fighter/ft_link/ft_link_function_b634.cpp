#pragma force_active on
extern "C" int fn_93_B68C();

extern "C" float fn_93_B634(char* base, void* unused, int i, int j) {
    char* p = base + fn_93_B68C() * 0x54;
    float* arr = *(float**)(p + i * 4 - 0x3e70);
    return arr[j];
}

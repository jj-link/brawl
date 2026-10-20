#pragma force_active on
extern "C" float fn_27_32D9F8(char* self, int unused, int a, int b) {
    int idx = a - *(int*)(self + 0x10);
    float* p = *(float**)(self + idx * 4 + 0x18);
    return p[b];
}

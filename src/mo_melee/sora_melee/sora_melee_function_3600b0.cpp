#pragma force_active on
extern "C" {
float fn_27_3600B0(char* self, int unused, int a, int b) {
    int i = a - *(int*)(self + 0x10);
    char* p = self + i * 4;
    float* base = *(float**)(p + 0x18);
    return base[b];
}
}

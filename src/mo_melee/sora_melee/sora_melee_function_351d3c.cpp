#pragma force_active on
extern "C" float fn_27_351D3C(char* self, int unused, int a, int b) {
    char* p = self + (a - *(int*)(self + 0x10)) * 4;
    float* arr = *(float**)(p + 0x18);
    return arr[b];
}

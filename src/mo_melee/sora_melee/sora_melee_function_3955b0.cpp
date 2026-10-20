#pragma force_active on
extern "C" float fn_27_3955B0(char* self, int unused, int a, int i) {
    int off = (a - *(int*)(self + 0x10)) * 4;
    float* arr = *(float**)(self + off + 0x18);
    return arr[i];
}

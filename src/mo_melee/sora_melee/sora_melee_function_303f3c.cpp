#pragma force_active on
extern "C" float fn_27_303F3C(char* p, int unused, int a, int b) {
    int n = *(int*)(p + 0x10);
    float* arr = *(float**)(p + ((a - n) << 2) + 0x18);
    return arr[b];
}

#pragma force_active on
extern "C" float fn_27_3241BC(char* base, int unused, int a, int b) {
    int off = (a - *(int*)(base + 0x10)) * 4;
    float* arr = *(float**)(base + off + 0x18);
    return arr[b];
}

#pragma force_active on
typedef unsigned int u32;

extern "C" {
float fn_27_3B3144(char* self, int unused, int a, int b)
{
    int idx = a - *(int*)(self + 0x10);
    float* arr = *(float**)(self + (idx << 2) + 0x18);
    return arr[b];
}
}

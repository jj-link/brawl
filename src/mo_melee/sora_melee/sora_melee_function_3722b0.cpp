#pragma force_active on
extern "C" {
float fn_27_3722B0(char* self, int unused, int a, int b)
{
    int base = *(int*)(self + 0x10);
    char* p = self + ((a - base) << 2);
    float* row = *(float**)(p + 0x18);
    return row[b];
}
}

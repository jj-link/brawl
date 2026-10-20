#pragma force_active on
typedef unsigned int u32;

extern "C" {
u32 fn_27_3B3164(char* self, int unused, int a, u32 idx)
{
    int off = (a - *(int*)(self + 0x14)) * 4;
    u32* arr = *(u32**)(self + off + 0x34);
    return arr[idx];
}
}

#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" u32 fn_27_303F5C(char* self, s32 a, s32 b, s32 idx)
{
    s32 off = (b - *(s32*)(self + 0x14)) * 4;
    u32* arr = *(u32**)(self + off + 0x20);
    return arr[idx];
}

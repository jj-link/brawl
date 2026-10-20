#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" s32 fn_27_1D081C(void* p)
{
    u32 x = *(u32*)((char*)p + 8);
    u32 r = (x << 4) | (x >> 28);
    return (s32)(r & 0xF8000000) >> 28;
}

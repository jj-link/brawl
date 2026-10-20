#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" s32 fn_27_1A4734(void* p)
{
    u32 x = *(u32*)((char*)p + 8);
    u32 r = (x << 20) | (x >> 12);
    return (s32)(r & 0xFFE00000) >> 22;
}

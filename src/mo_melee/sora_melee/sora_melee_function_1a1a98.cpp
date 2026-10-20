#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" s32 fn_27_1A1A98(void* p)
{
    u32 x = ((u32*)p)[2];
    u32 r = ((x << 6) | (x >> 26)) & 0xFE000000;
    return (s32)r >> 26;
}

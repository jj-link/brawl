#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" s32 fn_27_1B2630(u32 *p)
{
    u32 x = p[2];
    return (s32)(((x << 8) | (x >> 24)) & 0xF8000000) >> 28;
}

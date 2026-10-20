#pragma force_active on
typedef int s32;
typedef unsigned int u32;

extern "C" s32 fn_27_295FE8(s32 *p)
{
    return (s32)(((u32)p[2] << 5) & 0xFC000000u) >> 27;
}

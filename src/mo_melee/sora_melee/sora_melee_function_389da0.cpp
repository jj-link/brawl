#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" s32 fn_27_389DA0(u32 *p)
{
    return (s32)((p[2] << 8) & 0xF8000000) >> 28;
}

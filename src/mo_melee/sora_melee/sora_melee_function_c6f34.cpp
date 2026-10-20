#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" s32 fn_27_C6F34(u32 *p)
{
    u32 v = p[2];
    return ((s32)((v << 10) & 0xFC000000)) >> 27;
}

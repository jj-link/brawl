#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" s32 fn_72_52CC(u32 *p)
{
    u32 v = p[2];
    return ((s32)(((v >> 23) & 0x1F) << 27)) >> 28;
}

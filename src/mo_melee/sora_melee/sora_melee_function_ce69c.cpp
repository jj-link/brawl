#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" s32 fn_27_CE69C(u32 *p)
{
    u32 v = p[2];
    return (s32)((v << 9) & 0xFFC00000) >> 23;
}

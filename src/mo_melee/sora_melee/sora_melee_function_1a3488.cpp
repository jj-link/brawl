#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
s32 fn_27_1A3488(u32 *p)
{
    u32 x = p[2];
    return (s32)(((x >> 11) & 0x7FF) << 21) >> 22;
}
}

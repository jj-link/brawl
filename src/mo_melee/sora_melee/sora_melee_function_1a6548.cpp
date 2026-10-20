#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
s32 fn_27_1A6548(u32 *p)
{
    return (s32)((((p[2] >> 11) & 0x7FF) << 21)) >> 22;
}
}

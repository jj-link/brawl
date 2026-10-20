#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
s32 fn_27_19BEB8(u32 *p)
{
    u32 v = p[2];
    return (s32)(((v << 2) & 0xE0000000)) >> 30;
}
}

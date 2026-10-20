#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
s32 fn_27_1A14C8(u32 *p)
{
    u32 v = p[2];
    return (s32)(((v << 4) | (v >> 28)) & 0xF8000000) >> 28;
}
}

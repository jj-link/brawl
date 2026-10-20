#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
s32 fn_27_19F744(u32 *p)
{
    u32 v = p[2];
    v = (v << 8) & 0xF8000000;
    return (s32)v >> 28;
}
}

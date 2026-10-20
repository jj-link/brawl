#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
s32 fn_27_C5B3C(u32 *p)
{
    u32 t = p[2];
    t = t << 4;
    t = t & 0xE0000000;
    return (s32)t >> 30;
}
}

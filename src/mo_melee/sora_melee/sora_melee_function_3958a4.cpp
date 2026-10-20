#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
s32 fn_27_3958A4(u32 *p)
{
    u32 t = (p[2] >> 19) & 0x1F;
    return ((s32)(t << 27)) >> 28;
}
}

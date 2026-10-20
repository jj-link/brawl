#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
s32 fn_27_CFE84(void *p)
{
    u32 v = ((u32 *)p)[2];
    u32 r = (v << 7) | (v >> 25);
    return (s32)(r & 0xFF000000) >> 25;
}
}

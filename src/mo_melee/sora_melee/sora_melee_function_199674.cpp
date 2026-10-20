#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
s32 fn_27_199674(void *p)
{
    u32 x = ((u32 *)p)[2];
    u32 v = (x << 6) | (x >> 26);
    v &= 0xF0000000;
    return (s32)v >> 29;
}
}

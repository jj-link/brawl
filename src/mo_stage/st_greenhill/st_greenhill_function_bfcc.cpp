#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
s32 fn_72_BFCC(void *p)
{
    u32 v = ((u32 *)p)[2];
    u32 t = (v << 6) & 0xF0000000;
    return (s32)t >> 29;
}
}

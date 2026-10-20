#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
s32 fn_27_385C94(void *p)
{
    u32 v = ((u32 *)p)[2];
    v = (v << 3) & 0xF0000000;
    return (s32)v >> 29;
}
}

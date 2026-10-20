#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
s32 fn_27_1A6444(void *p)
{
    u32 v = *(u32 *)((char *)p + 8);
    v = ((v << 10) | (v >> 22)) & 0xFFE00000;
    return (s32)v >> 22;
}
}

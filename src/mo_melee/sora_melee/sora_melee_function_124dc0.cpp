#pragma force_active on
typedef int s32;
typedef unsigned int u32;

extern "C" s32 fn_27_124DC0(void *p)
{
    u32 v = ((u32 *)p)[2];
    u32 r = ((v << 6) | (v >> 26)) & 0xFE000000;
    return (s32)r >> 26;
}

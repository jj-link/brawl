#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" s32 fn_27_D0218(void *p)
{
    u32 v = ((u32 *)p)[2];
    u32 r = (v << 14) | (v >> 18);
    return (s32)(r & 0xFF000000) >> 25;
}

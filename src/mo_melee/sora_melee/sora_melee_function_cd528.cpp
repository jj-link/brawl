#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
s32 fn_27_CD528(void *p)
{
    u32 v = ((u32 *)p)[2];
    return (s32)((v << 2) & 0xE0000000u) >> 30;
}
}

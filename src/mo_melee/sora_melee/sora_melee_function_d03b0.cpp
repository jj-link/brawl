#pragma force_active on
typedef int s32;
typedef unsigned int u32;

extern "C" {
s32 fn_27_D03B0(void *p)
{
    u32 w = *(u32 *)((char *)p + 8);
    return (s32)((w << 14) & 0xFF000000) >> 25;
}
}

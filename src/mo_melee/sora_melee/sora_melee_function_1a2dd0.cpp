#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
s32 fn_27_1A2DD0(void *p)
{
    u32 w = *(u32 *)((char *)p + 8);
    return (s32)(((w << 4) | (w >> 28)) & 0xE0000000) >> 30;
}
}

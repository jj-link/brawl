#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
s32 fn_27_19BA34(void *p)
{
    u32 x = *(u32 *)((char *)p + 8);
    u32 y = ((x << 8) | (x >> 24)) & 0xF8000000;
    return (s32)y >> 28;
}
}

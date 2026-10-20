#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
s32 fn_27_385B04(void *p)
{
    u32 x = *(u32 *)((char *)p + 8);
    s32 y = (s32)(((x << 10) | (x >> 22)) & 0xFFE00000u);
    return y >> 22;
}
}

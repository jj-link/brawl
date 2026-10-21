#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" s32 fn_27_1A33E8(void *p)
{
    u32 w = *(u32 *)((char *)p + 8);
    s32 x = (s32)((w << 20) & 0xFFE00000);
    return x >> 22;
}

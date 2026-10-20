#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" s32 fn_27_1A5E2C(void *p)
{
    u32 x = *(u32 *)((char *)p + 8);
    u32 y = (x << 10) & 0xFFE00000;
    return ((s32)y) >> 22;
}

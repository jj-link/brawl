#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" s32 fn_62_A460(void *p)
{
    u32 x = ((u32 *)p)[2];
    x = ((x << 2) | (x >> 30)) & 0xE0000000;
    return (s32)x >> 30;
}

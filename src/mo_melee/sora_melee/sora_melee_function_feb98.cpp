#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" s32 fn_27_FEB98(void *p)
{
    u32 x = *(u32 *)((char *)p + 8);
    u32 r = (x << 2 | x >> 30) & 0xE0000000;
    return (s32)r >> 30;
}

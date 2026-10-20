#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" s32 fn_27_19C050(void *p)
{
    u32 x = *(u32 *)((char *)p + 8);
    u32 t = (x << 3) | (x >> 29);
    t &= 0xF0000000;
    return (s32)t >> 29;
}

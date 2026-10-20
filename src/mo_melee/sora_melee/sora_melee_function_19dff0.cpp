#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
s32 fn_27_19DFF0(void *p)
{
    u32 x = *(u32 *)((char *)p + 8);
    u32 rot = (x << 10) | (x >> 22);
    return (s32)(rot & 0xFC000000) >> 27;
}
}

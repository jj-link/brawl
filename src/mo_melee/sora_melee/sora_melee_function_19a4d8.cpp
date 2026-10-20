#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
s32 fn_27_19A4D8(void *p)
{
    u32 x = *(u32 *)((char *)p + 8);
    u32 r = (x << 5) | (x >> 27);
    return (s32)(r & 0xFC000000) >> 27;
}
}

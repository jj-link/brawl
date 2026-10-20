#pragma force_active on
typedef signed int s32;
typedef unsigned int u32;

extern "C" {
s32 fn_27_CA2F8(void *p)
{
    u32 x = *(u32 *)((char *)p + 8);
    return (s32)((x << 10) & 0xFC000000) >> 27;
}
}

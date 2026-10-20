#pragma force_active on
typedef unsigned int u32;
typedef signed int s32;

extern "C" {
s32 fn_27_19AECC(void *p)
{
    u32 x = *(u32 *)((char *)p + 8);
    u32 y = ((x << 10) | (x >> 22)) & 0xFC000000;
    return ((s32)y) >> 27;
}
}

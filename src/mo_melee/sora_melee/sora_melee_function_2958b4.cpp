#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
s32 fn_27_2958B4(void *p)
{
    u32 w = *(u32 *)((char *)p + 8);
    u32 t = ((w << 10) | (w >> 22)) & 0xFC000000;
    return (s32)t >> 27;
}
}

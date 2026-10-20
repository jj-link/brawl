#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
s32 fn_27_D0B44(void *p)
{
    u32 x = *(u32 *)((char *)p + 8);
    u32 r = (x << 7) | (x >> 25);
    return ((s32)(r & 0xFF000000)) >> 25;
}
}

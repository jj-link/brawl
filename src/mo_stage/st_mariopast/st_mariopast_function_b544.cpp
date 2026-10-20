#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
s32 fn_48_B544(void *p)
{
    u32 x = *(u32 *)((char *)p + 8);
    return (s32)(((x >> 14) | (x << 18)) & 0xFFC00000) >> 23;
}
}

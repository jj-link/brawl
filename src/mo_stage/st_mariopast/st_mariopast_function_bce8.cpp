#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" s32 fn_48_BCE8(void *p)
{
    u32 v = *(u32 *)((char *)p + 8);
    u32 t = (v << 6) & 0xFE000000;
    return (s32)t >> 26;
}

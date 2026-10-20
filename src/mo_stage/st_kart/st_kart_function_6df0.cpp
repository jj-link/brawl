#pragma force_active on
typedef unsigned int u32;
typedef int s32;
typedef unsigned char u8;

extern "C" s32 fn_49_6DF0(void *p)
{
    u32 x = *(u32 *)((u8 *)p + 8);
    s32 v = (s32)(((x >> 25) & 7) << 29);
    return v >> 30;
}

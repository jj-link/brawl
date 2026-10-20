#pragma force_active on
typedef int s32;
typedef unsigned int u32;

extern "C" s32 fn_27_1B1FA0(void *p)
{
    u32 x = ((u32 *)p)[2];
    s32 v = (s32)(((x >> 16) & 0x3F) << 26);
    return v >> 27;
}

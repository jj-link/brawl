#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" s32 fn_66_A3B4(void *p)
{
    return (s32)((((u32 *)p)[2] << 4) & 0xE0000000u) >> 30;
}

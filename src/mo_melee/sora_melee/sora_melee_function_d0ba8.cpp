#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" s32 fn_27_D0BA8(void *p)
{
    u32 x = *(u32 *)((char *)p + 8);
    s32 v = (s32)((x << 14) & 0xFF000000);
    return v >> 25;
}

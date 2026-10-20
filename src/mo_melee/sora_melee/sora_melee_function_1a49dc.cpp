#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" s32 fn_27_1A49DC(void *p)
{
    u32 v = *(u32 *)((char *)p + 8);
    return ((s32)(((v >> 23) & 0x1F) << 27)) >> 28;
}

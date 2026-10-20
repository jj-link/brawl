#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" s32 fn_27_1A411C(void *p)
{
    u32 v = *(u32 *)((char *)p + 8);
    u32 r = (v << 6) | (v >> 26);
    return ((s32)(r & 0xF0000000)) >> 29;
}

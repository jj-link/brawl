#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
s32 fn_27_1A623C(void *p)
{
    s32 v = *(s32 *)((char *)p + 8);
    return ((v << 10) & (s32)0xFFE00000) >> 22;
}
}

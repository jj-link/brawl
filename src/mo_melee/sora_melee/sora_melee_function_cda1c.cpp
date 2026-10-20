#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
s32 fn_27_CDA1C(void *p)
{
    u32 v = ((u32 *)p)[2];
    u32 r = (v << 4) | (v >> 28);
    return ((s32)(r & 0xE0000000)) >> 30;
}
}

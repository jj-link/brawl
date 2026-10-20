#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
s32 fn_27_72DDC(void *p)
{
    u32 v = (((u32 *)p)[2] >> 19) & 0x7F;
    return (s32)(v << 25) >> 26;
}
}

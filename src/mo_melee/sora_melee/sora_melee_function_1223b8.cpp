#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
s32 fn_27_1223B8(void *p)
{
    u32 x = ((u32 *)p)[2];
    return (s32)(((x >> 13) & 0x7F) << 25) >> 26;
}
}

#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

extern "C" {
s32 fn_27_19E238(void *p)
{
    u32 v = *(u32 *)((u8 *)p + 8);
    return (s32)((v << 12) & 0xFE000000) >> 26;
}
}

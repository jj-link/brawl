#pragma force_active on
typedef unsigned int u32;
typedef int s32;
typedef unsigned char u8;

extern "C" {
s32 fn_27_1A5918(void *p)
{
    u32 v = *(u32 *)((u8 *)p + 8);
    return (s32)((v << 5) & 0xFC000000) >> 27;
}
}

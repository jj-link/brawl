#pragma force_active on
typedef int s32;
typedef unsigned int u32;

extern "C" {
s32 fn_27_C51F8(void *p)
{
    u32 v = *(u32 *)((char *)p + 8);
    return (s32)((v << 2) & 0xE0000000) >> 30;
}
}

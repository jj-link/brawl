#pragma force_active on
typedef int s32;
typedef unsigned int u32;

extern "C" {
s32 fn_27_1A73C8(void *p)
{
    u32 v = *(u32 *)((char *)p + 8);
    return (s32)((v << 4) & 0xF8000000) >> 28;
}
}

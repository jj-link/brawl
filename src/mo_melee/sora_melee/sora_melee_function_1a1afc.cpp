#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
s32 fn_27_1A1AFC(void *p)
{
    u32 w = *(u32 *)((char *)p + 8);
    return (s32)((w << 12) & 0xFE000000) >> 26;
}
}

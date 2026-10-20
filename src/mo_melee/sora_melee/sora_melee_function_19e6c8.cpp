#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
s32 fn_27_19E6C8(void *p)
{
    u32 v = *(u32 *)((char *)p + 8);
    u32 r = ((v << 12) | (v >> 20)) & 0xFE000000;
    return (s32)r >> 26;
}
}

#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
s32 fn_27_2AC3E8(u32 *p)
{
    u32 x = p[1];
    return (s32)((x << 9) & 0xF0000000) >> 29;
}
}

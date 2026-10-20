#pragma force_active on
typedef signed int s32;
typedef unsigned int u32;

extern "C" {
s32 fn_27_1A63A4(u32* p)
{
    u32 w = p[2];
    return ((s32)((w << 20) & 0xFFE00000u)) >> 22;
}
}

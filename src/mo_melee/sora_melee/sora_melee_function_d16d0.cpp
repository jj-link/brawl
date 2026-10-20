#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
s32 fn_27_D16D0(u32 *p)
{
    return ((s32)((p[2] & 0xFF80) << 16)) >> 24;
}
}

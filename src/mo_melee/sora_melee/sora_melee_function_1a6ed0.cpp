#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
s32 fn_27_1A6ED0(u32* p)
{
    return ((s32)(((p[2] >> 1) & 0x7FF) << 21)) >> 22;
}
}

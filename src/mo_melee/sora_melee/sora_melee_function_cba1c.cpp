#pragma force_active on
typedef signed int s32;
typedef unsigned int u32;

extern "C" {
s32 fn_27_CBA1C(const u32 *p)
{
    return (s32)(((p[2] >> 23) & 0x1F) << 27) >> 28;
}
}

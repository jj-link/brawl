#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" s32 fn_27_CDED0(u32 *p)
{
    s32 v = (s32)((p[2] << 4) & 0xE0000000);
    return v >> 30;
}

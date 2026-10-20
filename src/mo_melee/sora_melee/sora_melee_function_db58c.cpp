#pragma force_active on
typedef int s32;
typedef unsigned int u32;

extern "C" {
s32 fn_27_DB58C(u32 *p)
{
    u32 x = p[2];
    u32 r = (x << 4) | (x >> 28);
    return (s32)(r & 0xE0000000) >> 30;
}
}

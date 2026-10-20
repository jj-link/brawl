#pragma force_active on
typedef signed int s32;

extern "C" {
s32 fn_27_CB130(s32 *p)
{
    s32 x = p[2];
    return (s32)((x << 10) & 0xFC000000) >> 27;
}
}

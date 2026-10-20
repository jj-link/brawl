#pragma force_active on
typedef int s32;

extern "C" {
s32 fn_27_19F218(s32 *p)
{
    s32 x = p[2];
    s32 y = (x << 6) & 0xFE000000;
    return y >> 26;
}
}

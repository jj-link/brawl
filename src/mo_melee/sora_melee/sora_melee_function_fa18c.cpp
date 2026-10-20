#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern "C" u8* fn_27_FA18C(u8* p, s32 idx)
{
    s32 v = *(s32*)(p + 0x18);
    s32 r = (v >> 30) + idx;
    if (r >= 1) {
        r -= 1;
    }
    return p + 0x1c + r * 12;
}

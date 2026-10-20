#pragma force_active on
typedef int s32;
typedef unsigned int u32;

extern "C" {
s32 fn_27_DB3AC(u32* p)
{
    u32 x = p[2];
    s32 r = (s32)((x << 6) & 0xF0000000);
    return r >> 29;
}
}

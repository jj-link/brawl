#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
s32 fn_27_199B3C(void* p)
{
    u32 w = ((u32*)p)[2];
    s32 v = (s32)(((w >> 16) & 0x3F) << 26);
    return v >> 27;
}
}

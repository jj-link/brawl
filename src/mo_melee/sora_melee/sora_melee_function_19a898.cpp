#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
s32 fn_27_19A898(u32* p)
{
    u32 w = p[2];
    u32 r = (w << 5) | (w >> 27);
    return (s32)(r & 0xFC000000) >> 27;
}
}

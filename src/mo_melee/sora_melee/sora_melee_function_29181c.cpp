#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
s32 fn_27_29181C(void* p)
{
    u32 v = ((u32*)p)[2];
    u32 r = (v << 4) | (v >> 28);
    r &= 0xF8000000;
    return (s32)r >> 28;
}
}

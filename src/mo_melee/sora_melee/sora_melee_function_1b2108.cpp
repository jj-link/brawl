#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
s32 fn_27_1B2108(void* p)
{
    u32 w = ((u32*)p)[2];
    return (s32)((w << 8) & 0xF8000000) >> 28;
}
}

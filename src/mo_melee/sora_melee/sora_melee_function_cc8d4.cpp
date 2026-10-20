#pragma force_active on
typedef int s32;
typedef unsigned int u32;

extern "C" {
s32 fn_27_CC8D4(void* p)
{
    u32 x = ((u32*)p)[2];
    return (s32)((x << 6) & 0xF0000000) >> 29;
}
}

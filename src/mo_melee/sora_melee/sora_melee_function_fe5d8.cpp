#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
s32 fn_27_FE5D8(void* p)
{
    u32 v = ((u32*)p)[2];
    u32 r = ((v << 2) | (v >> 30)) & 0xE0000000u;
    return (s32)r >> 30;
}
}

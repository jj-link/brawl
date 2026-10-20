#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" s32 fn_27_C4474(const void* p)
{
    u32 v = ((const u32*)p)[2];
    return (s32)((v << 12) & 0xFE000000) >> 26;
}

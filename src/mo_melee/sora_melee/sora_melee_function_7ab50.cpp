#pragma force_active on
typedef int s32;
typedef unsigned int u32;

extern "C" s32 fn_27_7AB50(void* p)
{
    u32 v = ((u32*)p)[2];
    return ((s32)((v >> 13 & 0x7F) << 25)) >> 26;
}

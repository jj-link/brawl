#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" s32 fn_27_CF090(void* p)
{
    u32 v = *(u32*)((char*)p + 8);
    u32 m = (v >> 13) & 0x7F;
    return (s32)(m << 25) >> 26;
}

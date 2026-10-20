#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" s32 fn_27_CF35C(void* p)
{
    return (s32)((*(u32*)((char*)p + 8) << 6) & 0xFE000000) >> 26;
}

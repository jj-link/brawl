#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" s32 fn_27_1CF9BC(void* p)
{
    u32 v = *(u32*)((char*)p + 8);
    u32 r = (v << 6) | (v >> 26);
    return (s32)(r & 0xFE000000u) >> 26;
}

#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" s32 fn_27_1A44C8(void* p)
{
    u32 v = *(u32*)((char*)p + 8);
    u32 t = (v >> 11) & 0x7FF;
    return ((s32)(t << 21)) >> 22;
}

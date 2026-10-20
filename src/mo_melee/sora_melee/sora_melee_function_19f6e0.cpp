#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" s32 fn_27_19F6E0(void* p)
{
    u32 v = (*(u32*)((char*)p + 8) >> 23) & 0x1F;
    return (s32)(v << 27) >> 28;
}

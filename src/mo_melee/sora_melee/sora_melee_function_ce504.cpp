#pragma force_active on
typedef int s32;
typedef unsigned int u32;

extern "C" s32 fn_27_CE504(void* p)
{
    u32 v = *(u32*)((char*)p + 8);
    u32 r = (v << 5) | (v >> 27);
    return (s32)(r & 0xFC000000) >> 27;
}

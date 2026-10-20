#pragma force_active on
typedef signed int s32;
typedef unsigned int u32;

extern "C" s32 fn_27_FE520(void* p)
{
    u32 x = *(u32*)((char*)p + 8);
    u32 r = (x << 3 | x >> 29) & 0xF0000000;
    return (s32)r >> 29;
}

#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
s32 fn_27_C7E24(void* p)
{
    u32 x = *(u32*)((char*)p + 4);
    return (s32)(((x << 15) | (x >> 17)) & 0xFC000000) >> 27;
}
}

#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
s32 fn_27_19EF4C(void* p)
{
    u32 v = *(u32*)((char*)p + 8);
    return (s32)((v << 10 | v >> 22) & 0xFC000000) >> 27;
}
}

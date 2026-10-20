#pragma force_active on
typedef int s32;
typedef unsigned int u32;

extern "C" {
s32 fn_27_19B35C(void* p)
{
    s32 v = *(s32*)((char*)p + 8);
    return ((s32)((u32)v << 10) & (s32)0xFC000000) >> 27;
}
}

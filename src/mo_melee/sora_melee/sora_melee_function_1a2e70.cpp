#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
s32 fn_27_1A2E70(void* p)
{
    u32 v = ((u32*)p)[2];
    v = (v << 5) | (v >> 27);
    return ((s32)(v & 0xFC000000)) >> 27;
}
}

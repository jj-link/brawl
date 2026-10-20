#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" s32 fn_27_A1BD8(void *p)
{
    u32 v = *(u32 *)((char *)p + 8);
    return ((s32)((v << 5) & 0xFC000000u)) >> 27;
}

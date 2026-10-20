#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" s32 fn_49_7018(void *obj)
{
    u32 v = *(u32 *)((char *)obj + 8);
    return (s32)((v << 8) & 0xF8000000) >> 28;
}

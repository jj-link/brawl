#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" s32 fn_27_D034C(void* self)
{
    u32 v = ((u32*)self)[2];
    return (s32)((v >> 17) << 24) >> 25;
}

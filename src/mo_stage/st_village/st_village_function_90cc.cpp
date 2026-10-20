#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
int fn_70_90CC(void *p)
{
    u32 v = ((u32 *)p)[2];
    return (s32)((v << 4) & 0xE0000000) >> 30;
}
}

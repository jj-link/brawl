#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
s32 fn_27_1A6D68(void *p)
{
    return (s32)((((u32 *)p)[2] << 10) & 0xFFE00000) >> 22;
}
}

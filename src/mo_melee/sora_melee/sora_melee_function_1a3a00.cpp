#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
int fn_27_1A3A00(void *p)
{
    u32 w = *(u32 *)((char *)p + 8);
    return (s32)((w << 20) & 0xFFE00000) >> 22;
}
}

#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
int fn_27_CFBB8(void *p)
{
    u32 x = *(u32 *)((char *)p + 8);
    return (s32)(((x >> 13) & 0x7F) << 25) >> 26;
}
}

#pragma force_active on
typedef unsigned int u32;
typedef int s32;

s32 fn_80351284(void *arg0)
{
    u32 v = *(u32 *)((char *)arg0 + 0x10);
    return ((((v >> 11) & 3) - 1) == 0);
}

#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
s32 fn_27_122BF0(void *p)
{
    u32 x = *(u32 *)((char *)p + 8);
    return ((s32)(((x << 6) | (x >> 26)) & 0xFE000000)) >> 26;
}
}

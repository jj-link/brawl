#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
s32 fn_27_D2C9C(void *p)
{
    u32 w = *(u32 *)((char *)p + 8);
    return (s32)((w << 4) & 0xF8000000u) >> 28;
}
}

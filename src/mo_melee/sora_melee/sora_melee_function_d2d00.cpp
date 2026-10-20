#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" s32 fn_27_D2D00(void *p)
{
    u32 v = *(u32 *)((char *)p + 8);
    u32 f = (v << 8) & 0xF8000000;
    return (s32)f >> 28;
}

#pragma force_active on
extern "C" typedef unsigned int u32;
extern "C" typedef int s32;

extern "C" s32 fn_27_CB884(void *p)
{
    u32 x = *(u32 *)((char *)p + 8);
    return (s32)((x << 3) & 0xF0000000) >> 29;
}

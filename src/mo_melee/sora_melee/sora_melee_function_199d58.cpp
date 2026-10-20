#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
s32 fn_27_199D58(void *p)
{
    return (s32)((((u32 *)p)[2] << 5) & 0xFC000000u) >> 27;
}
}

#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
s32 fn_27_C9E2C(void *p)
{
    u32 v = ((u32 *)p)[2];
    s32 r = (s32)(((v >> 25) & 7) << 29);
    return r >> 30;
}
}

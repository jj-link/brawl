#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
s32 fn_27_FEA28(void *p)
{
    u32 v = *(u32 *)((char *)p + 8);
    s32 t = (s32)(((v << 3) | (v >> 29)) & 0xF0000000);
    return t >> 29;
}
}

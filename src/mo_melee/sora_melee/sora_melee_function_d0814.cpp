#pragma force_active on
typedef unsigned int u32;
typedef int s32;
typedef unsigned char u8;

extern "C" {
s32 fn_27_D0814(void* p)
{
    u32 v = *(u32*)((u8*)p + 8);
    return (s32)(((v << 7) | (v >> 25)) & 0xFF000000u) >> 25;
}
}

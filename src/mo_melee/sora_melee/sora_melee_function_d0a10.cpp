#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;
typedef int s32;

extern "C" {
s32 fn_27_D0A10(void* p)
{
    u32 x = *(u32*)((u8*)p + 8);
    return (s32)(((x << 14) & 0xFF000000u)) >> 25;
}
}

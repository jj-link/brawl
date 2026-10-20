#pragma force_active on
typedef unsigned int u32;
typedef int s32;
typedef unsigned char u8;

extern "C" s32 fn_27_21BE00(void* p)
{
    u32 w = *(u32*)((u8*)p + 4);
    u32 r = (w << 24) | (w >> 8);
    return ((s32)(r & 0xFF800000)) >> 24;
}

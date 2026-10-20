#pragma force_active on
typedef int s32;
typedef unsigned int u32;

extern "C" s32 fn_27_CE038(void* p) {
    u32 x = ((u32*)p)[2];
    u32 r = (x << 8) | (x >> 24);
    return ((s32)(r & 0xFF800000)) >> 24;
}

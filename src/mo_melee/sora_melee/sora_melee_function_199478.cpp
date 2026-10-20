#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" s32 fn_27_199478(void* p) {
    u32 w = ((u32*)p)[2];
    u32 r = (w << 4) | (w >> 28);
    return (s32)(r & 0xF8000000u) >> 28;
}

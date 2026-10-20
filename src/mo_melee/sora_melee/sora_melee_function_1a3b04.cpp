#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
s32 fn_27_1A3B04(void* p) {
    u32 w = *(u32*)((char*)p + 8);
    u32 r = (w << 20) | (w >> 12);
    return ((s32)(r & 0xFFE00000)) >> 22;
}
}

#pragma force_active on
typedef unsigned int u32;

extern "C" {
int fn_40_289D0(void* p) {
    u32 x = ((u32*)p)[2];
    u32 r = (x << 8) | (x >> 24);
    return (int)(r & 0xF8000000u) >> 28;
}
}

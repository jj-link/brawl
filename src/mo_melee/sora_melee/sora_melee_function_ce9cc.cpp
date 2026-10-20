#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
s32 fn_27_CE9CC(void* p) {
    u32 v = ((u32*)p)[2];
    return (s32)((v << 6) & 0xFE000000u) >> 26;
}
}

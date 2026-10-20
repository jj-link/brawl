#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
s32 fn_27_19B114(void* p) {
    u32 x = ((u32*)p)[2];
    return (s32)((x >> 16) & 0x3F) << 26 >> 27;
}
}

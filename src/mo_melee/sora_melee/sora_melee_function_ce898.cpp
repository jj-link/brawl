#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
s32 fn_27_CE898(void* p) {
    u32 v = *(u32*)((char*)p + 8);
    s32 r = (s32)(((v << 12) | (v >> 20)) & 0xFE000000);
    return r >> 26;
}
}

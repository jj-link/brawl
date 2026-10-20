#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
s32 fn_27_D0D40(void* p) {
    u32 v = *(u32*)((char*)p + 8);
    u32 t = (v >> 10) & 0xFF;
    t <<= 24;
    return (s32)t >> 25;
}
}

#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" s32 fn_27_1A4428(void* p) {
    u32 v = *(u32*)((char*)p + 8);
    u32 w = ((v << 20) | (v >> 12)) & 0xFFE00000;
    return (s32)w >> 22;
}

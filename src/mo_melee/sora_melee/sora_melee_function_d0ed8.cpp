#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" s32 fn_27_D0ED8(void* p) {
    u32 v = *(u32*)((char*)p + 8);
    return (s32)((v << 14) & 0xFF000000) >> 25;
}

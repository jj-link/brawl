#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" s32 fn_27_1A3D0C(void* p) {
    u32 x = *(u32*)((char*)p + 8);
    return (s32)((x << 20) & 0xFFE00000) >> 22;
}

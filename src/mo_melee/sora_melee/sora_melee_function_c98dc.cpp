#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" s32 fn_27_C98DC(u32* p) {
    u32 x = p[2];
    u32 t = (x >> 25) & 0xF;
    return (s32)(t << 28) >> 29;
}

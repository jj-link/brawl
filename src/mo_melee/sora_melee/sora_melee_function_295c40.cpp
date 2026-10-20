#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" s32 fn_27_295C40(u32 *p) {
    u32 x = p[2];
    return ((s32)(((x << 3) | (x >> 29)) & 0xF0000000)) >> 29;
}

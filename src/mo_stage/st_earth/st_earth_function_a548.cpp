#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" s32 fn_66_A548(u32 *p) {
    return (s32)(((p[2] >> 27) & 7) << 29) >> 30;
}

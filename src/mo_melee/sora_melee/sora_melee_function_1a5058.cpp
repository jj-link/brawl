#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" s32 fn_27_1A5058(u32* p) {
    return ((s32)(p[2] << 10) & (s32)0xFC000000) >> 27;
}

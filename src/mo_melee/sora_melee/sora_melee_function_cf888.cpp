#pragma force_active on
typedef int s32;
typedef unsigned int u32;

extern "C" {
s32 fn_27_CF888(const u32* p) {
    s32 v = (s32)((p[2] << 12) & 0xFE000000);
    return v >> 26;
}
}

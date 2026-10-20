#pragma force_active on
typedef unsigned int u32;

extern "C" int fn_27_1A5F30(const u32* p) {
    return (int)((p[2] << 10) & 0xFFE00000) >> 22;
}

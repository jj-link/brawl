#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern "C" u32 fn_27_69EA4(u8* p) {
    u32 v = (p[0x34] >> 5) & 7;
    return v != 0;
}

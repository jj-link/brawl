#pragma force_active on
typedef unsigned char u8;

extern "C" {
void fn_8015DB3C(u8* dst, const u8* src) {
    dst[0x14] = src[0];
    dst[0x15] = src[1];
    dst[0x16] = src[2];
}
}

#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;

void fn_802544C4(u8* dst, u8* src) {
    if (*(u16*)(src + 0x12) & 1) dst[0] = src[0x0A];
    if (*(u16*)(src + 0x12) & 2) dst[1] = src[0x0B];
    if (*(u16*)(src + 0x12) & 4) dst[2] = src[0x0C];
    if (*(u16*)(src + 0x12) & 8) dst[3] = src[0x0D];
    if (*(u16*)(src + 0x12) & 0x10) dst[4] = src[0x0E];
    if (*(u16*)(src + 0x12) & 0x3F00) dst[5] = src[0x0F];
    if (*(u16*)(src + 0x12) & 0x20) dst[7] = src[0x10];
    if (*(u16*)(src + 0x12) & 0x40) dst[8] = src[0x11];
}

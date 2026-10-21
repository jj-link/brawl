#pragma force_active on
extern "C" {
typedef unsigned char u8;

u8* fn_80299C04(u8* base, int index) {
    return base + index * 0x30;
}
}

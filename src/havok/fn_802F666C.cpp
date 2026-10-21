#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;

extern "C" int fn_802F666C(u8 *arg0, u8 *arg1) {
    u16 a = *(u16 *)(*(u8 **)(*(u8 **)(arg0 + 4) + 0x58) + 0x20);
    u16 b = *(u16 *)(*(u8 **)(*(u8 **)(arg1 + 4) + 0x58) + 0x20);

    return (a < b || (a == b &&
        *(u16 *)(*(u8 **)(*(u8 **)(arg0 + 8) + 0x58) + 0x20) <
        *(u16 *)(*(u8 **)(*(u8 **)(arg1 + 8) + 0x58) + 0x20))) << 24;
}

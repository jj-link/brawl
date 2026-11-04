#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

s32 fn_803D8228(u8 *arg0) {
    u8 byte;
    s32 valid;
    u16 value;
    u16 word;

    byte = arg0[0];
    valid = 1;
    if ((byte != 0xEB || arg0[2] != 0x90) && byte != 0xE9) {
        valid = 0;
    }
    if (arg0[0x1FE] != 0x55 || arg0[0x1FF] != 0xAA) {
        valid = 0;
    }
    if ((u32)(arg0 + 0xB) & 1) {
        value = arg0[0xB] | (arg0[0xC] << 8);
    } else {
        word = *(u16 *)(arg0 + 0xC);
        value = ((word >> 8) & 0xFF) | ((word << 8) & 0xFF00);
    }
    if (value != 0x200 && value != 0x400 && value != 0x800 && value != 0x1000) {
        valid = 0;
    }
    byte = arg0[0xD];
    if (byte != 1 && byte != 2 && byte != 4 && byte != 8 && byte != 0x10 && byte != 0x20 && byte != 0x40 && byte != 0x80) {
        valid = 0;
    }
    byte = arg0[0x15];
    if (byte != 0xF0 && byte != 0xF8 && byte != 0xF9 && byte != 0xFA && byte != 0xFB && byte != 0xFC && byte != 0xFD && byte != 0xFE && byte != 0xFF) {
        valid = 0;
    }
    return valid;
}

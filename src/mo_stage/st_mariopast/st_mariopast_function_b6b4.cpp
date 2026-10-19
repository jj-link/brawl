#pragma force_active on
typedef unsigned char u8;

extern "C" u8* fn_48_B6B4(u8* base, int index) {
    int i = (*(int*)(base + 8) >> 23) + index;
    if (i >= 0xcd) {
        i -= 0xcd;
    }
    return base + i * 0x68 + 0xc;
}

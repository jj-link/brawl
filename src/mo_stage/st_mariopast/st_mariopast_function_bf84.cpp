#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern "C" u8* fn_48_BF84(u8* self, int index) {
    int i = (*(s32*)(self + 8) >> 26) + index;
    if (i >= 0x13) {
        i -= 0x13;
    }
    return self + i * 0x68 + 0xc;
}

#pragma force_active on
typedef unsigned char u8;

extern "C" u8* fn_74_6A90(u8* self, int index) {
    int i = (*(int*)(self + 8) >> 30) + index;
    if (i >= 1) {
        i = i - 1;
    }
    return self + i * 0x78 + 0xC;
}

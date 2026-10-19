#pragma force_active on
typedef unsigned char u8;

extern "C" u8* fn_48_B90C(u8* self, int index) {
    int r = (*(int*)(self + 8) >> 25) + index;
    if (r >= 0x3a) {
        r -= 0x3a;
    }
    return self + r * 0x78 + 0xc;
}

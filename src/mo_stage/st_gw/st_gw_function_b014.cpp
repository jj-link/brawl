#pragma force_active on
typedef unsigned char u8;

extern "C" u8* fn_63_B014(u8* self, int index) {
    int sign = *(int*)(self + 8) >> 30;
    int n = sign + index;
    if (n >= 1) {
        n -= 1;
    }
    return self + n * 0x78 + 0xc;
}

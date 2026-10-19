#pragma force_active on
typedef unsigned char u8;

extern "C" u8* fn_63_AEB4(u8* self, int index) {
    int shift = ((int*)self)[2] >> 30;
    int t = shift + index;
    if (t >= 1) {
        t -= 1;
    }
    return self + t * 0x38 + 0xC;
}

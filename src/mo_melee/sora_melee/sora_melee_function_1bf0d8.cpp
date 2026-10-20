#pragma force_active on
typedef unsigned char u8;

extern "C" void* fn_27_1BF0D8(u8* self, int idx) {
    int shift = *(int*)(self + 0x18) >> 26;
    int n = shift + idx;
    if (n >= 0x11) {
        n = n - 0x11;
    }
    return self + n * 12 + 0x1c;
}

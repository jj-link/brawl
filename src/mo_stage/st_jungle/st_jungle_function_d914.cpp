#pragma force_active on
typedef unsigned char u8;

extern "C" void* fn_51_D914(u8* self, int idx) {
    int s = *(int*)(self + 8) >> 29;
    int n = s + idx;
    if (n >= 2) {
        n -= 2;
    }
    return self + n * 0x38 + 0xc;
}

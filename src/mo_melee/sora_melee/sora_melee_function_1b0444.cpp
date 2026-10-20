#pragma force_active on
extern "C" void* fn_27_1B0444(unsigned char* self, int idx) {
    int x = *(int*)(self + 8) >> 28;
    int n = x + idx;
    if (n >= 5) {
        n -= 5;
    }
    return self + n * 0x5c + 0xc;
}

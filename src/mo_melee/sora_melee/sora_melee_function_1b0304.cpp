#pragma force_active on
extern "C" void* fn_27_1B0304(unsigned char* self, int idx) {
    int n = (*(int*)(self + 8) >> 26) + idx;
    if (n >= 20) {
        n -= 20;
    }
    return self + n * 0x60 + 0xC;
}

#pragma force_active on
extern "C" void* fn_49_6E98(unsigned char* p, int idx) {
    int n = (*(int*)(p + 8) >> 30) + idx;
    if (n >= 1) {
        n -= 1;
    }
    return p + n * 0x90 + 0xc;
}

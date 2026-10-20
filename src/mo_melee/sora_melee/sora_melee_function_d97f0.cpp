#pragma force_active on
extern "C" void* fn_27_D97F0(char* p, int idx) {
    int r0 = *(int*)(p + 8) >> 29;
    int n = r0 + idx;
    if (n >= 2) {
        n = n - 2;
    }
    return p + n * 0x5c + 0xc;
}

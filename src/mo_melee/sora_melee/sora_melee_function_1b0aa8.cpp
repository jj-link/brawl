#pragma force_active on
extern "C" void* fn_27_1B0AA8(char* p, int idx) {
    int n = *(int*)(p + 8) >> 26;
    int m = n + idx;
    if (m >= 16) {
        m -= 16;
    }
    return p + m * 24 + 12;
}

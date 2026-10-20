#pragma force_active on
extern "C" unsigned char* fn_27_1B0A80(unsigned char* base, int idx) {
    int s = *(int*)(base + 8) >> 29;
    int n = s + idx;
    if (n >= 2) {
        n -= 2;
    }
    return base + n * 56 + 12;
}

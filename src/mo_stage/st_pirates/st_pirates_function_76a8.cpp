#pragma force_active on
extern "C" char* fn_52_76A8(char* p, int idx) {
    int hi = *(int*)(p + 8) >> 28;
    int n = hi + idx;
    if (n >= 7) {
        n -= 7;
    }
    return p + (n << 3) + 12;
}

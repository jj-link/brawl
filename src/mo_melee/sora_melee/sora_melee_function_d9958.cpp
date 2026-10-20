#pragma force_active on
extern "C" char* fn_27_D9958(char* p, int n) {
    int v = *(int*)(p + 8) >> 28;
    int m = v + n;
    if (m >= 5) {
        m -= 5;
    }
    return p + m * 0x34 + 0xc;
}

#pragma force_active on
extern "C" char* fn_96_1E39C(char* base, int n) {
    int v = *(int*)(base + 8) >> 28;
    int t = v + n;
    if (t >= 7) {
        t = t - 7;
    }
    return base + (t << 3) + 0xc;
}

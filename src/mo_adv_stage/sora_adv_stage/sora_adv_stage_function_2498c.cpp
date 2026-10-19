#pragma force_active on
extern "C" char* fn_40_2498C(char* p, int idx) {
    int v = *(int*)(p + 8);
    int t = (v >> 30) + idx;
    if (t >= 1) {
        t = t - 1;
    }
    return p + t * 0xa0 + 0xc;
}

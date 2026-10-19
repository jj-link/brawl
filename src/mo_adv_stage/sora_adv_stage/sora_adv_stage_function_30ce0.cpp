#pragma force_active on
extern "C" char* fn_40_30CE0(char* p, int idx) {
    int t = *(int*)(p + 8) >> 27;
    int s = t + idx;
    if (s >= 13) {
        s -= 13;
    }
    return p + s * 120 + 12;
}

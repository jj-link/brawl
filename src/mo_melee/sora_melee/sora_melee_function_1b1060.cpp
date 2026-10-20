#pragma force_active on
extern "C" {
char* fn_27_1B1060(char* p, int idx) {
    int v = *(int*)(p + 8) >> 27;
    int n = v + idx;
    if (n >= 12) {
        n -= 12;
    }
    return p + n * 12 + 12;
}
}

#pragma force_active on
extern "C" char* fn_40_30C18(char* base, int idx) {
    int v = *(int*)(base + 8);
    int n = (v >> 27) + idx;
    if (n >= 13) {
        n -= 13;
    }
    return base + n * 104 + 12;
}

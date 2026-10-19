#pragma force_active on
extern "C" char* fn_54_6598(char* base, int n) {
    int i = (*(int*)(base + 8) >> 30) + n;
    if (i >= 1) {
        i -= 1;
    }
    return base + i * 0xa0 + 0xc;
}

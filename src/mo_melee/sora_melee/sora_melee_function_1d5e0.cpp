#pragma force_active on
extern "C" void* fn_27_1D5E0(char* p, int idx) {
    int t = *(int*)(p + 8) >> 28;
    int r = t + idx;
    if (r >= 4) {
        r -= 4;
    }
    return p + (r << 4) + 0xC;
}

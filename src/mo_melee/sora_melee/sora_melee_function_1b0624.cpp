#pragma force_active on
extern "C" char* fn_27_1B0624(char* base, int idx) {
    int n = *(int*)(base + 8);
    int r = (n >> 27) + idx;
    if (r >= 9) {
        r -= 9;
    }
    return base + r * 0x34 + 0xc;
}

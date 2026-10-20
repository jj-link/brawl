#pragma force_active on
extern "C" char* fn_27_1B069C(char* p, int idx) {
    int s = *(int*)(p + 8) >> 27;
    int n = s + idx;
    if (n >= 13) {
        n -= 13;
    }
    return p + 0xc + n * 0x34;
}

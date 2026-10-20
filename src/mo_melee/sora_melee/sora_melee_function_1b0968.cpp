#pragma force_active on
extern "C" char* fn_27_1B0968(char* p, int idx) {
    int a = *(int*)(p + 8) >> 22;
    int t = a + idx;
    if (t >= 0x11d) {
        t -= 0x11d;
    }
    return p + t * 4 + 0xc;
}

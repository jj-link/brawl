#pragma force_active on
extern "C" char* fn_56_651C(char* self, int idx) {
    int s = *(int*)(self + 8) >> 30;
    int t = s + idx;
    if (t >= 1) {
        t -= 1;
    }
    return self + t * 0x68 + 0xc;
}

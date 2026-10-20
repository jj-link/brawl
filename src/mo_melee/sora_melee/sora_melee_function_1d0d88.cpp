#pragma force_active on
extern "C" void* fn_27_1D0D88(char* self, int idx) {
    int s = *(int*)(self + 8) >> 26;
    int t = s + idx;
    if (t >= 16) {
        t -= 16;
    }
    return self + t * 12 + 12;
}

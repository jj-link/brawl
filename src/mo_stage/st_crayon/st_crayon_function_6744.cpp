#pragma force_active on
extern "C" void* fn_56_6744(unsigned char* self, int idx) {
    int v = *(int*)(self + 8);
    int s = v >> 28;
    int t = s + idx;
    if (t >= 7) {
        t -= 7;
    }
    return self + (t << 3) + 12;
}

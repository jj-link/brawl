#pragma force_active on
extern "C" void* fn_27_FF1BC(char* p, unsigned int idx) {
    int v = *(int*)(p + 8);
    int t = v >> 28;
    t = t + idx;
    if (t >= 4) {
        t -= 4;
    }
    return p + t * 12 + 12;
}

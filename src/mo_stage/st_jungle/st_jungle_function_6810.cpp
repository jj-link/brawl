#pragma force_active on
extern "C" void* fn_51_6810(void* self, int idx) {
    int v = *(int*)((char*)self + 8) >> 28;
    int t = v + idx;
    if (t >= 7) {
        t -= 7;
    }
    return (char*)self + (t << 3) + 0xc;
}

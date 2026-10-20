#pragma force_active on
extern "C" void* fn_27_1B13C0(void* self, int idx) {
    int v = *(int*)((char*)self + 8);
    int t = (v >> 28) + idx;
    if (t >= 6) {
        t -= 6;
    }
    return (char*)self + (t << 4) + 0xc;
}

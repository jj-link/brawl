#pragma force_active on
extern "C" void* fn_27_1B041C(void* self, int idx) {
    int t = ((int*)self)[2] >> 28;
    int s = t + idx;
    if (s >= 7) {
        s -= 7;
    }
    return (char*)self + s * 0x90 + 0xC;
}

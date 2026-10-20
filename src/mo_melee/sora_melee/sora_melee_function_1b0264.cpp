#pragma force_active on
extern "C" void* fn_27_1B0264(void* self, int idx) {
    int v = *(int*)((char*)self + 8);
    int t = v >> 27;
    int s = t + idx;
    if (s >= 15) {
        s -= 15;
    }
    return (char*)self + s * 16 + 12;
}

#pragma force_active on
extern "C" void* fn_27_1B124C(void* self, int idx) {
    int s = *(int*)((char*)self + 8) >> 29;
    int t = s + idx;
    if (t >= 2) {
        t -= 2;
    }
    return (char*)self + (t << 2) + 12;
}

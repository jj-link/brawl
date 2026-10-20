#pragma force_active on
extern "C" char* fn_27_FF274(char* self, int idx) {
    int v = *(int*)(self + 8);
    int i = (v >> 29) + idx;
    if (i >= 3) {
        i -= 3;
    }
    return self + i * 12 + 12;
}

#pragma force_active on
extern "C" char* fn_27_29605C(char* self, int idx) {
    int v = *(int*)(self + 8);
    int i = (v >> 27) + idx;
    if (i >= 9) {
        i -= 9;
    }
    return self + i * 12 + 12;
}

#pragma force_active on
extern "C" char* fn_27_FF32C(char* self, int idx) {
    int off = *(int*)(self + 8) >> 29;
    int n = off + idx;
    if (n >= 2) {
        n -= 2;
    }
    return self + n * 12 + 12;
}

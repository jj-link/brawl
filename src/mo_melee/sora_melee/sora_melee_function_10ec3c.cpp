#pragma force_active on
extern "C" char* fn_27_10EC3C(char* self, int idx) {
    int n = (*(int*)(self + 8) >> 27) + idx;
    if (n >= 8) {
        n = n - 8;
    }
    return self + n * 12 + 12;
}

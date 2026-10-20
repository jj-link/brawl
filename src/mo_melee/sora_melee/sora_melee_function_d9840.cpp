#pragma force_active on
extern "C" char* fn_27_D9840(char* self, int idx) {
    int n = (*(int*)(self + 8) >> 29) + idx;
    if (n >= 3) {
        n -= 3;
    }
    return self + n * 20 + 12;
}

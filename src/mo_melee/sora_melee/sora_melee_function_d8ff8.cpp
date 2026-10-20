#pragma force_active on
extern "C" char* fn_27_D8FF8(char* self, int idx) {
    int n = (*(int*)(self + 8) >> 28) + idx;
    if (n >= 7) {
        n -= 7;
    }
    return self + (n << 4) + 0xC;
}

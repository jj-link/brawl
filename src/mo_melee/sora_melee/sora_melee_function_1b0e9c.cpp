#pragma force_active on
extern "C" char* fn_27_1B0E9C(char* self, int idx) {
    int n = (*(int*)(self + 8) >> 29) + idx;
    n = (n >= 2) ? n - 2 : n;
    return self + n * 0x68 + 0xC;
}

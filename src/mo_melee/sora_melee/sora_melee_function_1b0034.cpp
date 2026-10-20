#pragma force_active on
extern "C" char* fn_27_1B0034(char* self, int idx) {
    int sel = *(int*)(self + 8);
    int n = (sel >> 28) + idx;
    if (n >= 6) {
        n -= 6;
    }
    return self + n * 0x68 + 0xC;
}

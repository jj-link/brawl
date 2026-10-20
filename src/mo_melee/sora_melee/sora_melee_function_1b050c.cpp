#pragma force_active on
extern "C" char* fn_27_1B050C(char* self, int idx) {
    int x = *(int*)(self + 8);
    int n = (x >> 26) + idx;
    if (n >= 16) {
        n -= 16;
    }
    return self + n * 0x68 + 0xC;
}

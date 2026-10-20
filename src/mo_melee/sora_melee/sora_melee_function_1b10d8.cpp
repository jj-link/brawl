#pragma force_active on
extern "C" void* fn_27_1B10D8(char* self, int idx) {
    int v = *(int*)(self + 8);
    int n = (v >> 28) + idx;
    if (n >= 4) {
        n -= 4;
    }
    return self + n * 0x68 + 0xc;
}

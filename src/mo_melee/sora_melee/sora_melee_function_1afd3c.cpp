#pragma force_active on
extern "C" void* fn_27_1AFD3C(char* self, int idx) {
    int n = (*(int*)(self + 8) >> 22) + idx;
    if (n >= 0x127) {
        n -= 0x127;
    }
    return self + 0xc + n * 4;
}

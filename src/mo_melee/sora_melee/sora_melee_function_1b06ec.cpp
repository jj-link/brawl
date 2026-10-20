#pragma force_active on
extern "C" void* fn_27_1B06EC(char* p, int idx) {
    int n = (*(int*)(p + 8) >> 30) + idx;
    if (n >= 1) {
        n -= 1;
    }
    return p + n * 0x8c + 0xc;
}

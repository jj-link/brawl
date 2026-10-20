#pragma force_active on
extern "C" void* fn_27_1B1150(char* p, int idx) {
    int r0 = *(int*)(p + 8) >> 30;
    int n = r0 + idx;
    if (n >= 1) {
        n = n - 1;
    }
    return p + n * 0x90 + 0xC;
}

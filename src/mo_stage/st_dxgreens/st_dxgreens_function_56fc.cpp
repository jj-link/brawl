#pragma force_active on
extern "C" void* fn_79_56FC(char* self, int index) {
    int n = *(int*)(self + 0x8) >> 26;
    int m = n + index;
    if (m >= 30) {
        m -= 30;
    }
    return self + m * 0x90 + 0xc;
}

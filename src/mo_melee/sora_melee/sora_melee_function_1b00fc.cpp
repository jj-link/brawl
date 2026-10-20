#pragma force_active on
extern "C" void* fn_27_1B00FC(char* self, int idx) {
    int v = *(int*)(self + 8);
    int n = (v >> 25) + idx;
    if (n >= 0x24) {
        n -= 0x24;
    }
    return self + (n << 4) + 0xc;
}

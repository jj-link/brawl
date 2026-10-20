#pragma force_active on
extern "C" void* fn_27_1AFE04(char* p, int idx) {
    int s = *(int*)(p + 8) >> 22;
    int n = s + idx;
    if (n >= 0x121) {
        n -= 0x121;
    }
    return p + n * 4 + 12;
}

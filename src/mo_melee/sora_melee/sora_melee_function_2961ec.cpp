#pragma force_active on
extern "C" void* fn_27_2961EC(char* p, int idx) {
    int n = (*(int*)(p + 8) >> 26) + idx;
    if (n >= 20) {
        n -= 20;
    }
    return p + 12 + n * 12;
}

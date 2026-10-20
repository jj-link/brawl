#pragma force_active on
extern "C" void* fn_27_295ECC(char* p, int idx) {
    int v = *(int*)(p + 8);
    int i = (v >> 29) + idx;
    if (i >= 2) {
        i -= 2;
    }
    return p + i * 12 + 12;
}

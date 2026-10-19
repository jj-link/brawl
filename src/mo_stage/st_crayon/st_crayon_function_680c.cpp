#pragma force_active on
extern "C" void* fn_56_680C(char* p, int i) {
    int r = (*(int*)(p + 8)) >> 28;
    int j = r + i;
    if (j >= 6) {
        j -= 6;
    }
    return p + (j << 3) + 12;
}

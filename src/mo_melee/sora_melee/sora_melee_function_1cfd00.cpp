#pragma force_active on
extern "C" void* fn_27_1CFD00(char* p, int idx) {
    int v = *(int*)(p + 8) >> 27;
    int i = v + idx;
    if (i >= 10) {
        i -= 10;
    }
    return p + i * 12 + 12;
}

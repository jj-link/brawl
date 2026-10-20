#pragma force_active on
extern "C" void* fn_27_2956CC(int* p, int idx) {
    int i = (p[2] >> 27) + idx;
    if (i >= 10) {
        i -= 10;
    }
    return (char*)p + (i << 2) + 12;
}

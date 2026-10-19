#pragma force_active on
extern "C" void* fn_47_4F8C(int* p, int idx) {
    int i = (p[2] >> 28) + idx;
    if (i >= 7) {
        i -= 7;
    }
    return (char*)p + (i << 3) + 0xc;
}

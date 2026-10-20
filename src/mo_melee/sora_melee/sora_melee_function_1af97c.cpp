#pragma force_active on
extern "C" void* fn_27_1AF97C(int* p, int idx) {
    int i = (p[2] >> 22) + idx;
    if (i >= 0x119) {
        i -= 0x119;
    }
    return (char*)p + i * 4 + 12;
}

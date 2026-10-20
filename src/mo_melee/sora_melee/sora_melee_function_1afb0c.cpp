#pragma force_active on
extern "C" void* fn_27_1AFB0C(int* p, int i) {
    int r = (p[2] >> 30) + i;
    if (r >= 1) {
        r = r - 1;
    }
    return (char*)p + (r << 2) + 0xc;
}

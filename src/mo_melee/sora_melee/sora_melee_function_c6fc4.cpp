#pragma force_active on
extern "C" void* fn_27_C6FC4(int* p, int idx) {
    int r = (p[2] >> 27) + idx;
    if (r >= 8) {
        r -= 8;
    }
    return (char*)p + (r << 2) + 0xC;
}

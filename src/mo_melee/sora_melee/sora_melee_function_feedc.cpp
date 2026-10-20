#pragma force_active on
extern "C" void* fn_27_FEEDC(int* p, int n) {
    int s = p[2] >> 27;
    int m = s + n;
    if (m >= 12) {
        m -= 12;
    }
    return (char*)p + m * 12 + 12;
}

#pragma force_active on
extern "C" void* fn_27_1AF9CC(int* p, int i) {
    int n = p[2] >> 27;
    int j = n + i;
    if (j >= 8) {
        j -= 8;
    }
    return (char*)p + (j << 2) + 12;
}

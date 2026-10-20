#pragma force_active on
extern "C" void* fn_27_1B129C(void* p, int idx) {
    int* base = (int*)p;
    int off = base[2] >> 30;
    int n = off + idx;
    if (n >= 1) {
        n--;
    }
    return (char*)p + n * 4 + 12;
}

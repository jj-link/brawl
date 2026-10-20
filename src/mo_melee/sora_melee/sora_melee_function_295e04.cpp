#pragma force_active on
extern "C" void* fn_27_295E04(void* p, int idx) {
    int n = (*(int*)((char*)p + 8) >> 28) + idx;
    if (n >= 4) {
        n -= 4;
    }
    return (char*)p + n * 8 + 12;
}

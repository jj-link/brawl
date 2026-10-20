#pragma force_active on
extern "C" int* fn_27_1AFB34(int* p, int i) {
    int n = (p[2] >> 27) + i;
    if (n >= 9) {
        n -= 9;
    }
    return (int*)((char*)p + n * 4 + 12);
}

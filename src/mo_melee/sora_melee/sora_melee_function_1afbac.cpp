#pragma force_active on
extern "C" int* fn_27_1AFBAC(int* p, int index) {
    int shift = p[2] >> 25;
    int result = shift + index;
    if (result >= 52)
        result -= 52;
    return p + result + 3;
}

#pragma force_active on
extern "C" void fn_40_30D08(unsigned int* p, unsigned int value) {
    unsigned int x = p[2];
    p[2] = __rlwimi(x, value, 17, 10, 14);
}

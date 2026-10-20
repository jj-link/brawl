#pragma force_active on
extern "C" void fn_27_295B4C(unsigned int* p, unsigned int value) {
    p[2] = __rlwimi(p[2], value, 20, 8, 11);
}

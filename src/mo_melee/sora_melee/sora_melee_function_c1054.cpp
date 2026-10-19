#pragma force_active on
extern "C" void fn_27_C136C(char* p, unsigned int n);

extern "C" void fn_27_C1054(char* p) {
    unsigned int n;
    fn_27_C136C(p, n);
    fn_27_C136C(p + 0x3c, n);
}

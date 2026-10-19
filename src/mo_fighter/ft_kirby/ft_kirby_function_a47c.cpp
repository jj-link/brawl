#pragma force_active on
extern "C" void* fn_27_1A6E10(void* p, short n);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_96_A47C(void* p, short n) {
    if (p != 0) {
        fn_27_1A6E10(p, (short)-1);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

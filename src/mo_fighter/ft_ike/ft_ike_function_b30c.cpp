#pragma force_active on
extern "C" void __dl__FPv(void* p);
extern "C" void* fn_119_91A4(void* p, short n);

extern "C" void* fn_119_B30C(void* p, short n) {
    if (p != 0) {
        fn_119_91A4(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

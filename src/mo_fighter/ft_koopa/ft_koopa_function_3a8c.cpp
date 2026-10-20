#pragma force_active on
extern "C" void* fn_102_3AE8(void* p, short n);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_102_3A8C(void* p, short n) {
    if (p != 0) {
        fn_102_3AE8(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

#pragma force_active on
extern "C" void __dl__FPv(void*);
extern "C" void* fn_119_1E6C(void* p, short n);

extern "C" void* fn_119_1E10(void* r3, short r4) {
    if (r3 != 0) {
        fn_119_1E6C(r3, 0);
        if (r4 > 0) {
            __dl__FPv(r3);
            r3 = r3;
        }
    }
    return r3;
}

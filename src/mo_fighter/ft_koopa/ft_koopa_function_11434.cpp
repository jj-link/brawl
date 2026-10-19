#pragma force_active on
extern "C" void* fn_27_1A64EC(void* p, short n);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_102_11434(void* p, short n) {
    if (p != 0) {
        int v = -1;
        fn_27_1A64EC(p, v);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

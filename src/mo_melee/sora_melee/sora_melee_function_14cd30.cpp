#pragma force_active on
extern "C" void* fn_27_C2E50(void* p, int n);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_27_14CD30(void* p, short n) {
    if (p != 0) {
        fn_27_C2E50(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

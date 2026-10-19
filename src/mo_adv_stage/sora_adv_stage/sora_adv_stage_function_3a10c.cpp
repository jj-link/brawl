#pragma force_active on
extern "C" void fn_40_24E00(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_40_3A10C(void* p, int n) {
    if (p) {
        fn_40_24E00(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

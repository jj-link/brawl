#pragma force_active on
extern "C" void fn_92_1B7C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_92_1BE0(void* p, int n) {
    if (p) {
        fn_92_1B7C(p, 0);
        if ((short)n > 0)
            __dl__FPv(p);
    }
    return p;
}

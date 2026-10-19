#pragma force_active on
extern "C" void* fn_110_451C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_110_6620(void* p, short n) {
    if (p != 0) {
        fn_110_451C(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

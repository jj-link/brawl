#pragma force_active on
extern "C" void* fn_112_10C6C(void* p, short n);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_112_10CAC(void* a, short b) {
    if (a != 0) {
        fn_112_10C6C(a, 0);
        if (b > 0) {
            __dl__FPv(a);
        }
    }
    return a;
}

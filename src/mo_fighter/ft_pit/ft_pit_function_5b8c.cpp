#pragma force_active on
extern "C" void* fn_27_1A3A44(void* p, short n);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_112_5B8C(void* p, short n) {
    if (p != 0) {
        fn_27_1A3A44(p, -1);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

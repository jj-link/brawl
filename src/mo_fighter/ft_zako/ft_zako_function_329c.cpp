#pragma force_active on
extern "C" void fn_27_1A3224(void* p, short n);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_126_329C(void* p, short n) {
    if (p != 0) {
        fn_27_1A3224(p, -1);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

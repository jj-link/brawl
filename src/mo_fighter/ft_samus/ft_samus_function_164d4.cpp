#pragma force_active on
extern "C" void fn_27_1A3A44(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_94_164D4(void* p, int n) {
    if (p != 0) {
        fn_27_1A3A44(p, static_cast<short>(-1));
        if (static_cast<short>(n) > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

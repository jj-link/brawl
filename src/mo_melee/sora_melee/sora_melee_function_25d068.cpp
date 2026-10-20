#pragma force_active on
extern "C" void* fn_27_25CEB8(void* p, int size);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_27_25D068(void* p, int doFree) {
    if (p) {
        fn_27_25CEB8(p, 0);
        if (doFree > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

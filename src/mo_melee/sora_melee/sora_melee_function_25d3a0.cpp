#pragma force_active on
extern "C" void* fn_27_25CEB8(void* p, int size);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_27_25D3A0(void* p, int flags) {
    if (p != 0) {
        fn_27_25CEB8(p, 0);
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

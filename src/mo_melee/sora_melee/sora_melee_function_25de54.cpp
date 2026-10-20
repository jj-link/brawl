#pragma force_active on
extern "C" void* fn_27_25CEB8(void* p, int size);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_27_25DE54(void* p, int size) {
    if (p) {
        fn_27_25CEB8(p, 0);
        if (size > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

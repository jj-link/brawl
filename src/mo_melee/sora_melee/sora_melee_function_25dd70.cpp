#pragma force_active on
extern "C" void* fn_27_25CEB8(void* p, int size);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_27_25DD70(void* a, int b) {
    if (a) {
        fn_27_25CEB8(a, 0);
        if (b > 0) {
            __dl__FPv(a);
        }
    }
    return a;
}

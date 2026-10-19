#pragma force_active on
extern "C" void fn_27_C9EDC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_122_A604(void* a, short b) {
    if (a != 0) {
        fn_27_C9EDC(a, -1);
        if (b > 0) {
            __dl__FPv(a);
        }
    }
    return a;
}

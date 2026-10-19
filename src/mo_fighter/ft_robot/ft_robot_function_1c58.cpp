#pragma force_active on
extern "C" {
    extern void fn_120_1B3C(void*, short);
    extern void __dl__FPv(void*);
}

extern "C" void* fn_120_1C58(void* a, short b) {
    if (a != 0) {
        fn_120_1B3C(a, 0);
        if (b > 0) {
            __dl__FPv(a);
        }
    }
    return a;
}

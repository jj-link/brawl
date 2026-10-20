#pragma force_active on
extern "C" void fn_27_240848(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_240B5C(void* a, int b) {
    if (a) {
        fn_27_240848(a, 0);
        if (b > 0)
            __dl__FPv(a);
    }
    return a;
}

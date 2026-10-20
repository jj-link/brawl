#pragma force_active on
extern "C" void* fn_27_B64B8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_1E096C(void* a, int b) {
    if (a) {
        fn_27_B64B8(a, -1);
        if (b > 0)
            __dl__FPv(a);
    }
    return a;
}

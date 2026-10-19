#pragma force_active on
extern "C" void* fn_27_A0C34(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_116_30B8(void* a, short b) {
    if (a) {
        fn_27_A0C34(a, -1);
        if (b > 0) {
            __dl__FPv(a);
        }
    }
    return a;
}

#pragma force_active on
extern "C" void* fn_27_5AE44(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_116_FEE8(void* p, short s) {
    if (p != 0) {
        fn_27_5AE44(p, -1);
        if (s > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

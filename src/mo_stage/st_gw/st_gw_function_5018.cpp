#pragma force_active on
extern "C" void fn_63_34F8(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_63_5018(void* p, int del) {
    if (p) {
        fn_63_34F8(p, 0);
        if (del > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

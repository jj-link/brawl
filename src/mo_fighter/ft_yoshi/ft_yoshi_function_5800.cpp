#pragma force_active on
extern "C" void fn_27_C96C0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_95_5800(void* p, short n) {
    if (p != 0) {
        fn_27_C96C0(p, static_cast<short>(-1));
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

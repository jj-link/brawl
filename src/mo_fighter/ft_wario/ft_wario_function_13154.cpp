#pragma force_active on
extern "C" void* fn_110_4FB4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_110_13154(void* p, short n) {
    if (p != 0) {
        fn_110_4FB4(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

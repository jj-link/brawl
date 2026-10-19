#pragma force_active on
extern "C" void fn_120_1208C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_120_120CC(void* p, short flags) {
    if (p != 0) {
        fn_120_1208C(p, 0);
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

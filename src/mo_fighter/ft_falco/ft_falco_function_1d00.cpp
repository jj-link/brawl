#pragma force_active on
extern "C" void fn_108_1B2C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_108_1D00(void* p, int flag) {
    if (p) {
        fn_108_1B2C(p, 0);
        if ((short)flag > 0)
            __dl__FPv(p);
    }
    return p;
}

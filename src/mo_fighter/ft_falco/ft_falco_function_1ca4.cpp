#pragma force_active on
extern "C" void fn_108_1B2C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_108_1CA4(void* p1, short p2) {
    if (p1 != 0) {
        fn_108_1B2C(p1, 0);
        if (p2 > 0) {
            __dl__FPv(p1);
        }
    }
    return p1;
}

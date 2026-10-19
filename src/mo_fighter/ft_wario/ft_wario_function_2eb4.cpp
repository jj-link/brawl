#pragma force_active on
extern "C" void* fn_27_19816C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_110_2EB4(void* p, short flags) {
    if (p != 0) {
        fn_27_19816C(p, -1);
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

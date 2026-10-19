#pragma force_active on
extern "C" void* fn_102_3A4C(void* p, short flags);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_102_A47C(void* p, short flag) {
    if (p != 0) {
        fn_102_3A4C(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

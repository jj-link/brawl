#pragma force_active on
typedef signed short s16;

extern "C" void fn_120_1B3C(void* p, s16 flag);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_120_1D10(void* p, s16 flag) {
    if (p != 0) {
        fn_120_1B3C(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

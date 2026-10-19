#pragma force_active on
typedef signed short s16;

extern "C" void fn_120_1B3C(void* p, s16 arg);

extern "C" void* fn_120_1D6C(void* p, s16 flag) {
    if (p != 0) {
        s16 zero = 0;
        fn_120_1B3C(p, zero);
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}

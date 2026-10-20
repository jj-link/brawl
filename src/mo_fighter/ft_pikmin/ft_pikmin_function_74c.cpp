#pragma force_active on
typedef signed short s16;

extern "C" void* fn_113_68C(void* p, s16 arg);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_113_74C(void* p, s16 flag) {
    if (p != 0) {
        s16 zero = 0;
        fn_113_68C(p, zero);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

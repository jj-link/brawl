#pragma force_active on
typedef signed short s16;

extern "C" {

extern void* fn_116_1ADC(void* p, s16 x);
extern void __dl__FPv(void* p);

void* fn_116_1D0C(void* arg1, s16 arg2) {
    if (arg1 != 0) {
        fn_116_1ADC(arg1, 0);
        if (arg2 > 0) {
            __dl__FPv(arg1);
        }
    }
    return arg1;
}
}

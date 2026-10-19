#pragma force_active on
extern "C" {
void fn_116_1ADC(void* a, short b);
void __dl__FPv(void* a);

void* fn_116_1C54(void* a, short b) {
    if (a != 0) {
        fn_116_1ADC(a, 0);
        if (b > 0) {
            __dl__FPv(a);
        }
    }
    return a;
}
}

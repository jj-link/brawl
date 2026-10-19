#pragma force_active on
extern "C" {

void fn_116_1ADC(void* a, short b);
void __dl__FPv(void* ptr);

void* fn_116_1CB0(void* a, int b) {
    if (a != 0) {
        fn_116_1ADC(a, 0);
        if ((short)b > 0) {
            __dl__FPv(a);
        }
    }
    return a;
}

}

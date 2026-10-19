#pragma force_active on
extern "C" {
    void fn_116_1ADC(void* p, short x);
    void __dl__FPv(void* p);

    void* fn_116_1B9C(void* arg0, int arg1) {
        if (arg0) {
            fn_116_1ADC(arg0, 0);
            if ((short)arg1 > 0) {
                __dl__FPv(arg0);
            }
        }
        return arg0;
    }
}

#pragma force_active on
extern "C" {
void* fn_116_1ADC(void*, short);
void __dl__FPv(void*);

void* fn_116_1B40(void* p0, short p1) {
    if (p0 != 0) {
        fn_116_1ADC(p0, 0);
        if (p1 > 0) {
            __dl__FPv(p0);
        }
    }
    return p0;
}
}

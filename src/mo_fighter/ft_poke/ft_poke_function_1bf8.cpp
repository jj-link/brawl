#pragma force_active on
extern "C" {
typedef signed short s16;
typedef signed int s32;

void fn_116_1ADC(void* p, s16 flag);
void __dl__FPv(void* p);

void* fn_116_1BF8(void* p, s32 flag) {
    if (p != 0) {
        fn_116_1ADC(p, 0);
        if ((s16)flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}

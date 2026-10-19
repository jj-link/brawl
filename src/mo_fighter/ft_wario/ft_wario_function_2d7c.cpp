#pragma force_active on
extern "C" void fn_27_C21DC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_110_2D7C(void* r3, short r4) {
    if (r3 != 0) {
        fn_27_C21DC(r3, -1);
        if (r4 > 0) {
            __dl__FPv(r3);
        }
    }
    return r3;
}

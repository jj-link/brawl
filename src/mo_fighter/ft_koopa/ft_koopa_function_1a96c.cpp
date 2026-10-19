#pragma force_active on
extern "C" void* fn_27_1A2D10(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_102_1A96C(void* a1, short a2) {
    if (a1) {
        fn_27_1A2D10(a1, -1);
        if (a2 > 0) {
            __dl__FPv(a1);
        }
    }
    return a1;
}

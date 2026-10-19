#pragma force_active on
extern "C" void* fn_27_CC7EC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_102_5E1C(void* a, short b) {
    if (a != 0) {
        fn_27_CC7EC(a, -1);
        if (b > 0) {
            __dl__FPv(a);
        }
    }
    return a;
}

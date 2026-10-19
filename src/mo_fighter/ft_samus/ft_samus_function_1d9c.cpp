#pragma force_active on
extern "C" void* fn_94_1DF8(void* p, short flag);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_94_1D9C(void* a, short b) {
    if (a != 0) {
        fn_94_1DF8(a, 0);
        if (b > 0) {
            __dl__FPv(a);
        }
    }
    return a;
}

#pragma force_active on
extern "C" void fn_104_1B48(void* a, short b);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_104_1AEC(void* a, short b) {
    if (a) {
        fn_104_1B48(a, 0);
        if (b > 0) {
            __dl__FPv(a);
        }
    }
    return a;
}

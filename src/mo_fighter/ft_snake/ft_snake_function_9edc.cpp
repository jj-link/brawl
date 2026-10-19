#pragma force_active on
extern "C" void fn_27_1540CC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_122_9EDC(void* arg1, short arg2) {
    if (arg1) {
        fn_27_1540CC(arg1, -1);
        if (arg2 > 0) {
            __dl__FPv(arg1);
        }
    }
    return arg1;
}

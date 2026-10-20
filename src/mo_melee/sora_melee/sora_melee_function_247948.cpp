#pragma force_active on
extern "C" void __dl__FPv(void*);
extern "C" void* fn_27_2474BC(void* arg1, int arg2);

extern "C" void* fn_27_247948(void* arg1, int arg2) {
    if (arg1) {
        fn_27_2474BC(arg1, 0);
        if (arg2 > 0) {
            __dl__FPv(arg1);
        }
    }
    return arg1;
}

#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_B7B14(void* arg1, int arg2) {
    if (arg1 && arg2 > 0) {
        __dl__FPv(arg1);
    }
    return arg1;
}

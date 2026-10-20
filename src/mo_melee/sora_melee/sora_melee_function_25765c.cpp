#pragma force_active on
extern "C" {
    void fn_27_241EA4(void* a1, int a2);
    void __dl__FPv(void*);
}

extern "C" void* fn_27_25765C(void* arg1, int arg2) {
    if (arg1) {
        if (arg1)
            fn_27_241EA4(arg1, 0);
        if (arg2 > 0)
            __dl__FPv(arg1);
    }
    return arg1;
}

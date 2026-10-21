#pragma force_active on
extern "C" {
    void fn_801CA7E8(void* a1);
    void __dl__FPv(void*);
}

extern "C" void* fn_8007312C(void* arg1, int arg2) {
    if (arg1) {
        if (arg1)
            fn_801CA7E8(arg1);
        if (arg2 > 0)
            __dl__FPv(arg1);
    }
    return arg1;
}

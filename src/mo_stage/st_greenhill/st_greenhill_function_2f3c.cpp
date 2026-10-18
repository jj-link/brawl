#pragma force_active on
extern "C" {
void __dl__FPv(void*);
}

extern "C" void* fn_72_2F3C(void* arg1, int arg2) {
    if (arg1 != 0 && arg2 > 0) {
        __dl__FPv(arg1);
    }
    return arg1;
}

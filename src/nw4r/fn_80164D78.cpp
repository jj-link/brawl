#pragma force_active on
extern "C" {
void* fn_80164D78(void* arg0, int arg1);
}

extern "C" void __dl__FPv(void*);

extern "C" void* fn_80164D78(void* arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        __dl__FPv(arg0);
    }
    return arg0;
}

#pragma force_active on
extern "C" {
void fn_80182894(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_80187D3C(void* arg0, int arg1) {
    if (arg0) {
        fn_80182894(arg0, 0);
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}

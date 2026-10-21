#pragma force_active on
extern "C" {
void fn_8015C238(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_801CABE8(void* arg0, int arg1) {
    if (arg0) {
        fn_8015C238(arg0, 0);
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}

#pragma force_active on
extern "C" {
void fn_68_A150(void* p, int flag);
void __dl__FPv(void* p);
}

extern "C" void* fn_68_E80C(void* p, int n) {
    if (p) {
        fn_68_A150(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

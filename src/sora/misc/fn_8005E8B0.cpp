#pragma force_active on
extern "C" {
void fn_80064284(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_8005E8B0(void* p, int n) {
    if (p) {
        fn_80064284(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

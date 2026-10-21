#pragma force_active on
extern "C" {
void fn_801C6B38(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_801C0CEC(void* p, int n) {
    if (p) {
        fn_801C6B38(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

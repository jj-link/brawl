#pragma force_active on
extern "C" {
void fn_8015ECB8(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_80160254(void* p, int n) {
    if (p) {
        fn_8015ECB8(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

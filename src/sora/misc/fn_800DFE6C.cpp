#pragma force_active on
extern "C" {
void fn_800726A8(void* p, int flag);
void __dl__FPv(void*);
}

extern "C" void* fn_800DFE6C(void* p, int n) {
    if (p) {
        fn_800726A8(p, -1);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

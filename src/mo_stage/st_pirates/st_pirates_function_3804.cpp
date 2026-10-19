#pragma force_active on
extern "C" {
void fn_52_363C(void* p, int flags);
void __dl__FPv(void* p);
}

extern "C" void* fn_52_3804(void* p, int n) {
    if (p) {
        fn_52_363C(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void fn_52_363C(void* self, int flag);

extern "C" void* fn_52_4360(void* p, int n) {
    if (p) {
        fn_52_363C(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

#pragma force_active on
extern "C" void fn_52_363C(void* self, int flags);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_52_F83C(void* p, int del) {
    if (p) {
        fn_52_363C(p, 0);
        if (del > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

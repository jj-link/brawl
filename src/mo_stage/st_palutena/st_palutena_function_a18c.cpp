#pragma force_active on
extern "C" void fn_67_A084(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_67_A18C(void* p, int n) {
    if (p) {
        fn_67_A084(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

#pragma force_active on
extern "C" void fn_115_1B08(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_115_1B6C(void* p, int n) {
    if (p) {
        fn_115_1B08(p, 0);
        if ((short)n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

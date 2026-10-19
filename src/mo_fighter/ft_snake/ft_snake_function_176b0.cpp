#pragma force_active on
extern "C" void* fn_122_4C3C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_122_176B0(void* p, int size) {
    if (p != 0) {
        fn_122_4C3C(p, 0);
        if ((short)size > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

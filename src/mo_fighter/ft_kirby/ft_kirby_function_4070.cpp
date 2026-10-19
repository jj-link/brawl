#pragma force_active on
extern "C" void fn_27_64D9C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_96_4070(void* p, int n) {
    if (p != 0) {
        fn_27_64D9C(p, -1);
        if ((short)n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

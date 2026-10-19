#pragma force_active on
extern "C" void fn_104_CCD4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_104_CD4C(void* p, int n) {
    if (p != 0) {
        fn_104_CCD4(p, 0);
        if ((short)n > 0)
            __dl__FPv(p);
    }
    return p;
}

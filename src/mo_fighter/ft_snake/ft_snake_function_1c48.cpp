#pragma force_active on
extern "C" void fn_122_1AD0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_122_1C48(void* p, int flag) {
    if (p) {
        fn_122_1AD0(p, 0);
        if ((short)flag > 0)
            __dl__FPv(p);
    }
    return p;
}

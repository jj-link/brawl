#pragma force_active on
extern "C" void fn_100_AE5C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_100_AEBC(void* p, int flag) {
    if (p) {
        fn_100_AE5C((char*)p + 8, -1);
        if ((short)flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

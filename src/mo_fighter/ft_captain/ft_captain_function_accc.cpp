#pragma force_active on
extern "C" void fn_100_AC70(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_100_ACCC(void* p, int flag) {
    if (p) {
        fn_100_AC70((char*)p + 4, -1);
        if ((short)flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

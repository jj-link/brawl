#pragma force_active on
extern "C" void fn_41_5B2B0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_5B078(void* p, int flag) {
    if (p != 0) {
        fn_41_5B2B0((char*)p + 8, -1);
        if ((short)flag > 0)
            __dl__FPv(p);
    }
    return p;
}

#pragma force_active on
extern "C" void fn_41_40000(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_4006C(void* p, int flag) {
    if (p != 0) {
        fn_41_40000((char*)p + 4, -1);
        if ((short)flag > 0)
            __dl__FPv(p);
    }
    return p;
}

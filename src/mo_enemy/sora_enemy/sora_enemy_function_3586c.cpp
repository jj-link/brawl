#pragma force_active on
extern "C" void fn_41_35960(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_3586C(void* p, int dtorFlag) {
    if (p != 0) {
        fn_41_35960((char*)p + 8, -1);
        if ((short)dtorFlag > 0)
            __dl__FPv(p);
    }
    return p;
}

#pragma force_active on
extern "C" void fn_124_9764(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_97C4(void* p, int dtor) {
    if (p) {
        fn_124_9764((char*)p + 8, -1);
        if ((short)dtor > 0)
            __dl__FPv(p);
    }
    return p;
}

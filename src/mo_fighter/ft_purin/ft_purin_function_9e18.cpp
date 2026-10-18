#pragma force_active on
extern "C" void fn_124_9DB8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_9E18(void* p, int destroy) {
    if (p != 0) {
        fn_124_9DB8((char*)p + 8, -1);
        if ((short)destroy > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

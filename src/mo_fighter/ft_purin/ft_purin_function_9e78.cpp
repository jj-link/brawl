#pragma force_active on
extern "C" void fn_124_9E18(void*, short);
extern "C" void fn_124_9CE0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_9E78(void* p, int destroy) {
    if (p != 0) {
        fn_124_9E18((char*)p + 0x17c, -1);
        if (p != 0) {
            fn_124_9CE0(p, 0);
        }
        if ((short)destroy > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

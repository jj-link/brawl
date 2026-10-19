#pragma force_active on
extern "C" void fn_124_9A2C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_9BC4(void* p, int flag) {
    if (p != 0) {
        fn_124_9A2C(p, 0);
        if ((short)flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

#pragma force_active on
extern "C" void fn_94_1AD0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_94_1CA4(void* object, int destroy) {
    if (object != 0) {
        fn_94_1AD0(object, 0);
        if ((short)destroy > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

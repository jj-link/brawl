#pragma force_active on
extern "C" void fn_110_1BE0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_110_1D58(void* object, int count) {
    if (object != 0) {
        fn_110_1BE0(object, 0);
        if ((short)count > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

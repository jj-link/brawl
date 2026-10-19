#pragma force_active on
extern "C" void* fn_27_14CD30(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_120_2BB8(void* object, int size) {
    if (object != 0) {
        fn_27_14CD30(object, -1);
        if ((short)size > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

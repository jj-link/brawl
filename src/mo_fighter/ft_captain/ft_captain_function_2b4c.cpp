#pragma force_active on
extern "C" void* fn_27_14CD30(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_100_2B4C(void* object, int flag) {
    if (object != 0) {
        fn_27_14CD30(object, -1);
        if ((short)flag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

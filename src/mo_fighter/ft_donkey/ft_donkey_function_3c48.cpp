#pragma force_active on
extern "C" void* fn_92_3CA4(void* object, short flags);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_92_3C48(void* object, int flags) {
    if (object != 0) {
        fn_92_3CA4(object, 0);
        if ((short)flags > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

#pragma force_active on
extern "C" void* fn_112_451C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_112_C094(void* object, short flags) {
    if (object != 0) {
        fn_112_451C(object, 0);
        if (flags > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

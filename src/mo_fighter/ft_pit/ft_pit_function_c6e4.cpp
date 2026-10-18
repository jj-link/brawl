#pragma force_active on
extern "C" void fn_112_451C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_112_C6E4(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            short baseDeleting = 0;
            fn_112_451C(object, baseDeleting);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

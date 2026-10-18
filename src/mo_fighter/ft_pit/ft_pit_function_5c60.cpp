#pragma force_active on
extern "C" void __dl__FPv(void*);
extern "C" void fn_112_5CC0(void*, short);

extern "C" void* fn_112_5C60(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            short baseDeleting = 0;
            fn_112_5CC0(object, baseDeleting);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

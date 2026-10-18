#pragma force_active on
extern "C" void* fn_97_4C84(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_97_CA34(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            short baseDeleting = 0;
            fn_97_4C84(object, baseDeleting);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

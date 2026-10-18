#pragma force_active on
extern "C" void fn_120_9940(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_120_B030(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            short baseDeleting = 0;
            fn_120_9940(object, baseDeleting);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

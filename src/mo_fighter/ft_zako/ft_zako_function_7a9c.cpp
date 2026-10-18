#pragma force_active on
extern "C" void fn_126_7438(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_126_7A9C(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            short baseDeleting = 0;
            fn_126_7438(object, baseDeleting);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

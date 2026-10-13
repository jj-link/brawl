void operator delete(void*);
extern "C" void* fn_117_A614(void*, short);

extern "C" void* fn_117_C3A8(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            short baseDeleting = 0;
            fn_117_A614(object, baseDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

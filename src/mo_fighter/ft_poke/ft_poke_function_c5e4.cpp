#pragma force_active on
void operator delete(void*);
extern "C" void* fn_116_3844(void*, short);

extern "C" void* fn_116_C5E4(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            short baseDeleting = 0;
            fn_116_3844(object, baseDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

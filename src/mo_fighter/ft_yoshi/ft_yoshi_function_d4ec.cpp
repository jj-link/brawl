#pragma force_active on
void operator delete(void*);

extern "C" void* fn_95_3864(void*, short);

extern "C" void* fn_95_D4EC(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            short baseDeleting = 0;
            fn_95_3864(object, baseDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

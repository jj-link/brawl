#pragma force_active on
void operator delete(void*);

extern "C" void* fn_95_657C(void*, short);

extern "C" void* fn_95_651C(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            short baseDeleting = 0;
            fn_95_657C(object, baseDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

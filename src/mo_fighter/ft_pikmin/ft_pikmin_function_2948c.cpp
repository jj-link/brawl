#pragma force_active on
void operator delete(void*);

extern "C" void* fn_113_2908(void*, short);

extern "C" void* fn_113_2948C(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            short baseDeleting = 0;
            fn_113_2908(object, baseDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

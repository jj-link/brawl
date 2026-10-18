#pragma force_active on
void operator delete(void*);

extern "C" void* fn_126_3470(void*, short);

extern "C" void* fn_126_3410(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            short baseDeleting = 0;
            fn_126_3470(object, baseDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

#pragma force_active on
void operator delete(void*);

extern "C" void* fn_97_4C84(void*, short);

extern "C" void* fn_97_D268(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            short baseDeleting = 0;
            fn_97_4C84(object, baseDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

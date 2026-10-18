#pragma force_active on
void operator delete(void*);

extern "C" void* fn_108_4C80(void*, short);

extern "C" void* fn_108_CDAC(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            short baseDeleting = 0;
            fn_108_4C80(object, baseDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

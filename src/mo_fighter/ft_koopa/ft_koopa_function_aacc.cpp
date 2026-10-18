#pragma force_active on
void operator delete(void*);

extern "C" void* fn_102_3A4C(void*, short);
extern "C" void* fn_102_AACC(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            short baseDeleting = 0;
            fn_102_3A4C(object, baseDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

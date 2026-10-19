#pragma force_active on
extern "C" void operator delete(void*);
extern "C" void* fn_119_91A4(void*, short);

extern "C" void* fn_119_11484(void* object, short deleting) {
    if (object != 0) {
        short baseDeleting = 0;
        fn_119_91A4(object, baseDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

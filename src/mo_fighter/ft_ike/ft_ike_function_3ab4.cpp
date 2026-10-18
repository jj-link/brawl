#pragma force_active on
void operator delete(void*);

extern "C" void* fn_119_3B14(void*, short);

extern "C" void* fn_119_3AB4(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            short baseDeleting = 0;
            fn_119_3B14(object, baseDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

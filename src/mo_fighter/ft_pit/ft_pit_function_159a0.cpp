#pragma force_active on
void operator delete(void*);

extern "C" void* fn_112_4480(void*, short);

extern "C" void* fn_112_159A0(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            short baseDeleting = 0;
            fn_112_4480(object, baseDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A15B8(void*, short);

extern "C" void* fn_119_43F4(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            short baseDeleting = -1;
            fn_27_1A15B8(object, baseDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

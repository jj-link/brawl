#pragma force_active on
void operator delete(void*);
extern "C" void* fn_102_1B290(void*, short);

extern "C" void* fn_102_1B1D4(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            short baseDeleting = 0;
            fn_102_1B290(object, baseDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

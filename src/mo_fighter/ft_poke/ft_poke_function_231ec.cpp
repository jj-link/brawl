#pragma force_active on
void operator delete(void*);

extern "C" void* fn_116_1DAB8(void*, short);

extern "C" void* fn_116_231EC(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            short baseDeleting = 0;
            fn_116_1DAB8(object, baseDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

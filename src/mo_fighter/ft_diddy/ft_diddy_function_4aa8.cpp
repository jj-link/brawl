#pragma force_active on
void operator delete(void*);

extern "C" void* fn_115_4B08(void*, short);

extern "C" void* fn_115_4AA8(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            short baseDeleting = 0;
            fn_115_4B08(object, baseDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

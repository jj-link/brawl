#pragma force_active on
void operator delete(void*);

extern "C" void* fn_95_45D8(void*, short);

extern "C" void* fn_95_7820(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            short baseDeleting = 0;
            fn_95_45D8(object, baseDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

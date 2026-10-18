#pragma force_active on
void operator delete(void*);
extern "C" void* fn_120_3F58(void*, short);

extern "C" void* fn_120_3EF8(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            short baseDeleting = 0;
            fn_120_3F58(object, baseDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

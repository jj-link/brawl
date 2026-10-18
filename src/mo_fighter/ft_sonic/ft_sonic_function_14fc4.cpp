#pragma force_active on
void operator delete(void*);
extern "C" void* fn_123_39AC(void*, short);

extern "C" void* fn_123_14FC4(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            short baseDeleting = 0;
            fn_123_39AC(object, baseDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

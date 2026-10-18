#pragma force_active on
void operator delete(void*);
extern "C" void* fn_123_4424(void*, short);

extern "C" void* fn_123_6620(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            short baseDeleting = 0;
            fn_123_4424(object, baseDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

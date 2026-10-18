#pragma force_active on
void operator delete(void*);
extern "C" void* fn_97_37F8(void*, short);

extern "C" void* fn_97_10700(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            short baseDeleting = 0;
            fn_97_37F8(object, baseDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

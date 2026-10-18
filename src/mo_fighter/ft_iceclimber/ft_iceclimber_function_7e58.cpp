#pragma force_active on
void operator delete(void*);
extern "C" void* fn_105_48D8(void*, short);

extern "C" void* fn_105_7E58(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            short baseDeleting = 0;
            fn_105_48D8(object, baseDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

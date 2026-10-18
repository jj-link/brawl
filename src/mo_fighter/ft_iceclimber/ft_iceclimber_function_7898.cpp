#pragma force_active on
void operator delete(void*);
extern "C" void* fn_105_45E4(void*, short);

extern "C" void* fn_105_7898(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            short baseDeleting = 0;
            fn_105_45E4(object, baseDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

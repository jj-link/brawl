#pragma force_active on
void operator delete(void*);
extern "C" void* fn_109_41F0(void*, short);

extern "C" void* fn_109_6014(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            short baseDeleting = 0;
            fn_109_41F0(object, baseDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

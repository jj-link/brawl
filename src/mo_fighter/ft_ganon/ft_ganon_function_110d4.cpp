#pragma force_active on
void operator delete(void*);

extern "C" void* fn_109_11094(void*, short);

extern "C" void* fn_109_110D4(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            short baseDeleting = 0;
            fn_109_11094(object, baseDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

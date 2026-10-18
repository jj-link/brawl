#pragma force_active on
void operator delete(void*);

extern "C" void* fn_94_14690(void*, short);

extern "C" void* fn_94_1FB64(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            short baseDeleting = 0;
            fn_94_14690(object, baseDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

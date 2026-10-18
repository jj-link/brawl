#pragma force_active on
void operator delete(void*);
extern "C" void* fn_110_3A60(void*, short);

extern "C" void* fn_110_1C738(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            short baseDeleting = 0;
            fn_110_3A60(object, baseDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

#pragma force_active on
extern "C" void* fn_113_3208(void*, short);
void operator delete(void*);

extern "C" void* fn_113_5C50(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            short baseDeleting = 0;
            fn_113_3208(object, baseDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

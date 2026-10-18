#pragma force_active on
void operator delete(void*);
extern "C" void* fn_108_6650(void*, short);

extern "C" void* fn_108_65F0(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            short baseDeleting = 0;
            fn_108_6650(object, baseDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

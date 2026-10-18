#pragma force_active on
void operator delete(void*);
extern "C" void* fn_110_451C(void*, short);

extern "C" void* fn_110_65C0(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            short baseDeleting = 0;
            fn_110_451C(object, baseDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

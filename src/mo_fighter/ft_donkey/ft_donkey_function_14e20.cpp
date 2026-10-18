#pragma force_active on
void operator delete(void*);
extern "C" void* fn_92_395C(void*, short);

extern "C" void* fn_92_14E20(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            short baseDeleting = 0;
            fn_92_395C(object, baseDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

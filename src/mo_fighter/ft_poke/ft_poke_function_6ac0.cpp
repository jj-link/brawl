#pragma force_active on
void operator delete(void*);

extern "C" void* fn_116_4150(void*, short);

extern "C" void* fn_116_6AC0(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            short baseDeleting = 0;
            fn_116_4150(object, baseDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

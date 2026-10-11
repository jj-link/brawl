void operator delete(void*);
extern "C" void* fn_118_4DD8(void*, short);

// Destroy the base subobject without freeing it before honoring the caller's flag.
extern "C" void* fn_118_13BFC(void* object, short deleting) {
    if (object != 0) {
        fn_118_4DD8(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

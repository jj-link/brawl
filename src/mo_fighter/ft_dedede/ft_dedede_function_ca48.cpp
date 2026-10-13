void operator delete(void*);
extern "C" void* fn_117_C8B0(void*, short);

// Destroy the base without freeing storage; the outer signed flag owns deletion.
extern "C" void* fn_117_CA48(void* object, short deleting) {
    if (object != 0) {
        short baseDeleting = 0;
        fn_117_C8B0(object, baseDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

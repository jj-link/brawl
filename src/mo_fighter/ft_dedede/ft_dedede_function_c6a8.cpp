void operator delete(void*);
extern "C" void* fn_117_C648(void*, short);
extern "C" void* fn_117_C528(void*, short);

// Keep the complete receiver opaque; only the observed +0x60 teardown is needed.
extern "C" void* fn_117_C6A8(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_117_C648(static_cast<unsigned char*>(object) + 0x60, memberDeleting);
        short baseDeleting = 0;
        fn_117_C528(object, baseDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

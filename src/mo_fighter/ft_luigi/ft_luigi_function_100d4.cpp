extern "C" void* fn_99_10130(void*, short);

// Destroy the base without releasing storage, then honor the deleting flag.
extern "C" void* fn_99_100D4(void* object, short deleting) {
    if (object) {
        int destroyBase = 0;
        fn_99_10130(object, destroyBase);
        if (deleting > 0) operator delete(object);
    }
    return object;
}

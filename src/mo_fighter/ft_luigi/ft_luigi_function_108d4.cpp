extern "C" void* fn_99_41E0(void*, short);

// Destroy the base without releasing storage, then honor the deleting flag.
extern "C" void* fn_99_108D4(void* object, short deleting) {
    if (object) {
        int destroyBase = 0;
        fn_99_41E0(object, destroyBase);
        if (deleting > 0) operator delete(object);
    }
    return object;
}

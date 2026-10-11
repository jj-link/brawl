extern "C" void* fn_99_4144(void*, short);

// Destroy the module without releasing storage, then honor the deleting flag.
extern "C" void* fn_99_10018(void* object, short deleting) {
    if (object) {
        int destroyBase = 0;
        fn_99_4144(object, destroyBase);
        if (deleting > 0) operator delete(object);
    }
    return object;
}

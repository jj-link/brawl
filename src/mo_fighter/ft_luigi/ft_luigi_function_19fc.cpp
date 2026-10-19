#pragma force_active on
extern "C" void* fn_99_1A58(void*, short);

// Destroy the module without releasing storage, then honor the deleting flag.
extern "C" void* fn_99_19FC(void* object, short deleting) {
    if (object) {
        int destroyBase = 0;
        fn_99_1A58(object, destroyBase);
        if (deleting > 0) operator delete(object);
    }
    return object;
}

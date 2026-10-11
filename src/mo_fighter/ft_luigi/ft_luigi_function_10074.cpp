extern "C" void* fn_99_10130(void*, short);

// Destroy the base without releasing storage; only the outer destructor deletes.
extern "C" void* fn_99_10074(void* object, short deleting) {
    if (object) {
        if (object) {
            int destroyBase = 0;
            fn_99_10130(object, destroyBase);
        }
        if (deleting > 0) operator delete(object);
    }
    return object;
}

extern "C" void* fn_99_1029C(void*, short);

// Destroy the base without releasing storage; only the outer destructor deletes.
extern "C" void* fn_99_102DC(void* object, short deleting) {
    if (object) {
        if (object) {
            int destroyBase = 0;
            fn_99_1029C(object, destroyBase);
        }
        if (deleting > 0) operator delete(object);
    }
    return object;
}

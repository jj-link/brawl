#pragma force_active on
extern "C" void* fn_99_3298(void*, short);

extern "C" void* fn_99_323C(void* object, short deleting) {
    if (object) {
        fn_99_3298(object, 0);
        if (deleting > 0) operator delete(object);
    }
    return object;
}

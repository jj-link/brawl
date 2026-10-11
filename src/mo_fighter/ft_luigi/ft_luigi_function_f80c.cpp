extern "C" void* fn_99_F868(void*, short);

extern "C" void* fn_99_F80C(void* object, short deleting) {
    if (object) {
        int destroyBase = 0;
        fn_99_F868(object, destroyBase);
        if (deleting > 0) operator delete(object);
    }
    return object;
}

extern "C" void* fn_99_4034(void*, short);

extern "C" void* fn_99_FD2C(void* object, short deleting) {
    if (object) {
        int destroyBase = 0;
        fn_99_4034(object, destroyBase);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
